/* enable strdup() declaration in string.h */
#if defined(__linux__) || defined(__linux) || defined(__gnu_linux__)
  #define _BSD_SOURCE 1  /* for popen and pclose */
  #define CMD "md5sum"
#else
  #define CMD "md5"
#endif

#include <stdio.h>
#include "parts.h"
#include "test_runner.h"

#define PRINT(l,s) printf("%d: %s\n", (l), (s))
#define PT(l,p) printf("%d: %p\n", (l), (p))

#define MD5_LEN 32
static char *disk_checksum(char *filename)
{
  FILE *pipe;
  static char md5[MD5_LEN + 1];  /* static so we can return it */
  char cmd[255];

  sprintf(cmd, "%s %s | grep -Eo '[a-f0-9]{32}'", CMD, filename);

  if ((pipe = popen(cmd, "r")) == NULL)
    exit_error(__FILE__, cmd);

  if (fgets(md5, MD5_LEN + 1, pipe) == NULL)
    print_error(__FILE__, filename); /* don't exit: try to close the pipe */

  if (pclose(pipe) == EOF)
    exit_error(__FILE__, filename);

  return md5;
}

int read_one_part_test(void)
{
  Parts db;
  _assert((db = load_parts("../data/one-part.dat")));
  Part p;
  _assert(size(db) == 1);
  _assert((p = find_part(db, 10)));
  _assert(get_part_number(p) == 10);
  _assert(get_part_on_hand(p) == 198);
  _assert(get_part_price(p) == 7000);
  _assert(strcmp(get_part_name(p), "Ball Washer") == 0);

  destroy_db(db);
  return 0;
}
int write_one_part_test(void)
{
  Parts db = new_db(10);
  char *file = "../data/test.dat";
  char *md5;
  insert_part(db, set_part(13, "Bat fruit", 1, 1200));
  md5 = "1783e722d30721a126314a2774244ecd";
  _assert(dump(file, db) == 0);
  _assert(strcmp(disk_checksum(file), md5) == 0);

  destroy_db(db);
  remove(file);
  return 0;
}
int read_two_parts_test(void)
{
  Parts db;
  _assert((db = load_parts("../data/two-parts.dat")));
  _assert(size(db) == 2);

  Part p;
  _assert((p = find_part(db, 97)));
  _assert(get_part_price(p) == 123220);
  destroy_db(db);
  return 0;
}
int write_two_parts_test(void)
{
  Parts db = new_db(10);
  char *file = "../data/test.dat";
  char *md5;
  insert_part(db, set_part(13, "Bat fruit", 1, 1200));
  insert_part(db, set_part(19, "Bat Wing Hammer", 1000, 13200));
  md5 = "322e17a974b145068c1fa57907d50d48";
  _assert(dump(file, db) == 0);
  _assert(strcmp(disk_checksum(file), md5) == 0);

  destroy_db(db);
  remove(file);
  return 0;
}
int read_several_parts_test(void)
{
  Parts db;
  Part p;
  _assert((db = load_parts("../data/21-parts.dat")));

  _assert(size(db) == 21);
  _assert((p = find_part(db, 3497)));
  _assert(strcmp(get_part_name(p), "Sink, burbling") == 0);
  _assert(get_part_price(p) == 12720);
  _assert(get_part_on_hand(p) == 47);
  destroy_db(db);
  return 0;
}
int write_several_parts_test(void)
{
  Parts db = new_db(10);

  insert_part(db, set_part(50, "manual key sort plucker", 11, 89));
  insert_part(db, set_part(40, "Parts List Catalog Index", 19, 0));
  insert_part(db, set_part(99, "funnel lip, unfinished", 1010, 4344));
  insert_part(db, set_part(512, "caterpiller feet, left", 1010, 99));
  insert_part(db, set_part(101, "Mental Health Services", 40, 100));
  insert_part(db, set_part(2, "Gas Ring, Municipal", 18, 214798900));

  char *md5 = "ac246148784a7e387271f80637ca6676";
  char *file = "../data/test.dat";
  _assert(dump(file, db) == 0);
  _assert(strcmp(disk_checksum(file), md5) == 0);

  destroy_db(db);
  remove(file);
  return 0;
}
int read_many_parts_test(void)
{
  Parts db;
  _assert((db = load_parts("../data/100k-parts.dat")));

  _assert(size(db) == 100000);
  _assert(find_part(db, 700500));
  destroy_db(db);
  return 0;
}
int write_many_parts_test(void)
{
  Parts db;
  _assert((db = load_parts("../data/100k-parts.dat")));

  _assert(size(db) == 100000);
  char *md5 = "b69837f88ba23802c94519f4087fc6bc";
  char *file = "../data/test.dat";
  _assert(dump(file, db) == 0);
  _assert(strcmp(disk_checksum(file), md5) == 0);

  destroy_db(db);
  remove(file);
  return 0;
}
#define FLUSH_FILE "../data/flush-parts.dat"
int flush_to_disk_test(void)
{
  Parts dbA, dbB;
  dbA = new_db(10);
  char *original_md5;

  remove(FLUSH_FILE);
  insert_part(dbA, set_part(1, "A", 1, 100));
  _assert(size(dbA) == 1);

  original_md5 = "af0048599428dd1488104dcbc1e8239b";
  _assert(flush_to_disk(FLUSH_FILE, dbA) == 0);
  destroy_db(dbA);
  _assert(strcmp(disk_checksum(FLUSH_FILE), original_md5) == 0);

  dbB = new_db(10);
  insert_part(dbB, set_part(2, "B", 2, 200));
  _assert(size(dbB) == 1);

  _assert(flush_to_disk(FLUSH_FILE, dbB) == 0);
  _assert(strcmp(disk_checksum(FLUSH_FILE), original_md5) != 0);
  _assert(size(dbB) == 0);

  _assert((dbA = load_parts(FLUSH_FILE)));
  _assert(size(dbA) == 2);
  _assert(find_part(dbA, 1));
  _assert(find_part(dbA, 2));
  destroy_db(dbA);

  insert_part(dbB, set_part(3, "C", 3, 300));
  _assert(size(dbB) == 1);

  _assert(flush_to_disk(FLUSH_FILE, dbB) == 0);
  _assert(size(dbB) == 0);
  destroy_db(dbB);

  _assert((dbA = load_parts(FLUSH_FILE)));
  _assert(size(dbA) == 3);
  _assert(find_part(dbA, 1));
  _assert(find_part(dbA, 2));
  _assert(find_part(dbA, 3));
  destroy_db(dbA);

  remove(FLUSH_FILE);

  return 0;
}
int all_tests(void)
{
  _run(read_one_part_test);
  _run(write_one_part_test);
  _run(read_two_parts_test);
  _run(write_two_parts_test);
  _run(read_several_parts_test);
  _run(write_several_parts_test);
  _run(read_many_parts_test);
  _run(write_many_parts_test);
  _run(flush_to_disk_test);

  return 0;
}
