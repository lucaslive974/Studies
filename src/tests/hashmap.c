#include "hashmap.h"
#include <assert.h>
#include <stdio.h>

/* ========= Helpers de teste ========= */
static void print_test_ok(const char *name) { printf("[PASS] %s\n", name); }

static void test_insert_and_has(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 10, 100);

    assert(hasMapInt(&map, 10) == TRUE);
    assert(getMapInt(&map, 10) == 100);

    freeMap(&map);
    print_test_ok("test_insert_and_has passed");
}

static void test_update_existing_key(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 10, 100);
    insertEntryInMapInt(&map, 10, 999);

    assert(hasMapInt(&map, 10) == TRUE);
    assert(getMapInt(&map, 10) == 999);

    freeMap(&map);
    print_test_ok("test_update_existing_key passed");
}

static void test_delete_existing_key(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 10, 100);
    deleteEntryInMapInt(&map, 10);

    assert(hasMapInt(&map, 10) == FALSE);
    assert(getMapInt(&map, 10) == 0);

    freeMap(&map);
    print_test_ok("test_delete_existing_key passed");
}

static void test_delete_nonexistent_key(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 1, 10);
    insertEntryInMapInt(&map, 2, 20);

    deleteEntryInMapInt(&map, 999);

    assert(hasMapInt(&map, 1) == TRUE);
    assert(hasMapInt(&map, 2) == TRUE);
    assert(getMapInt(&map, 1) == 10);
    assert(getMapInt(&map, 2) == 20);

    freeMap(&map);
    print_test_ok("test_delete_nonexistent_key passed");
}

static void test_collision_handling(void) {
    UnorderedMapInt map = createMap(4);

    /* Todos colidem se hash = key % 4 */
    insertEntryInMapInt(&map, 1, 100);
    insertEntryInMapInt(&map, 5, 500);
    insertEntryInMapInt(&map, 9, 900);

    assert(hasMapInt(&map, 1) == TRUE);
    assert(hasMapInt(&map, 5) == TRUE);
    assert(hasMapInt(&map, 9) == TRUE);

    assert(getMapInt(&map, 1) == 100);
    assert(getMapInt(&map, 5) == 500);
    assert(getMapInt(&map, 9) == 900);

    freeMap(&map);
    print_test_ok("test_collision_handling passed");
}

static void test_delete_middle_of_collision_chain(void) {
    UnorderedMapInt map = createMap(4);

    insertEntryInMapInt(&map, 1, 100);
    insertEntryInMapInt(&map, 5, 500);
    insertEntryInMapInt(&map, 9, 900);

    deleteEntryInMapInt(&map, 5);

    assert(hasMapInt(&map, 1) == TRUE);
    assert(hasMapInt(&map, 5) == FALSE);
    assert(hasMapInt(&map, 9) == TRUE);

    assert(getMapInt(&map, 1) == 100);
    assert(getMapInt(&map, 9) == 900);

    freeMap(&map);
    print_test_ok("test_delete_middle_of_collision_chain passed");
}

static void test_get_nonexistent_key(void) {
    UnorderedMapInt map = createMap(8);

    assert(hasMapInt(&map, 123) == FALSE);
    assert(getMapInt(&map, 123) == 0);

    freeMap(&map);
    print_test_ok("test_get_nonexistent_key passed");
}
/* ========= Advanced tests ========= */

static void test_many_insertions(void) {
    UnorderedMapInt map = createMap(128);

    for (int i = 0; i < 1000; i++) {
        insertEntryInMapInt(&map, i, i * 10);
    }

    for (int i = 0; i < 1000; i++) {
        assert(hasMapInt(&map, i) == TRUE);
        assert(getMapInt(&map, i) == i * 10);
    }

    freeMap(&map);
    print_test_ok("test_many_insertions");
}

static void test_extreme_collisions(void) {
    UnorderedMapInt map = createMap(1);

    for (int i = 0; i < 200; i++) {
        insertEntryInMapInt(&map, i, i + 1000);
    }

    for (int i = 0; i < 200; i++) {
        assert(hasMapInt(&map, i) == TRUE);
        assert(getMapInt(&map, i) == i + 1000);
    }

    freeMap(&map);
    print_test_ok("test_extreme_collisions");
}

static void test_delete_beginning_of_chain(void) {
    UnorderedMapInt map = createMap(4);

    insertEntryInMapInt(&map, 1, 100);
    insertEntryInMapInt(&map, 5, 500);
    insertEntryInMapInt(&map, 9, 900);

    deleteEntryInMapInt(&map, 1);

    assert(hasMapInt(&map, 1) == FALSE);
    assert(hasMapInt(&map, 5) == TRUE);
    assert(hasMapInt(&map, 9) == TRUE);
    assert(getMapInt(&map, 5) == 500);
    assert(getMapInt(&map, 9) == 900);

    freeMap(&map);
    print_test_ok("test_delete_beginning_of_chain");
}

static void test_delete_middle_of_chain(void) {
    UnorderedMapInt map = createMap(4);

    insertEntryInMapInt(&map, 1, 100);
    insertEntryInMapInt(&map, 5, 500);
    insertEntryInMapInt(&map, 9, 900);

    deleteEntryInMapInt(&map, 5);

    assert(hasMapInt(&map, 1) == TRUE);
    assert(hasMapInt(&map, 5) == FALSE);
    assert(hasMapInt(&map, 9) == TRUE);
    assert(getMapInt(&map, 1) == 100);
    assert(getMapInt(&map, 9) == 900);

    freeMap(&map);
    print_test_ok("test_delete_middle_of_chain");
}

static void test_delete_end_of_chain(void) {
    UnorderedMapInt map = createMap(4);

    insertEntryInMapInt(&map, 1, 100);
    insertEntryInMapInt(&map, 5, 500);
    insertEntryInMapInt(&map, 9, 900);

    deleteEntryInMapInt(&map, 9);

    assert(hasMapInt(&map, 1) == TRUE);
    assert(hasMapInt(&map, 5) == TRUE);
    assert(hasMapInt(&map, 9) == FALSE);
    assert(getMapInt(&map, 1) == 100);
    assert(getMapInt(&map, 5) == 500);

    freeMap(&map);
    print_test_ok("test_delete_end_of_chain");
}

static void test_reinsert_after_delete(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 42, 100);
    deleteEntryInMapInt(&map, 42);

    assert(hasMapInt(&map, 42) == FALSE);
    assert(getMapInt(&map, 42) == 0);

    insertEntryInMapInt(&map, 42, 999);

    assert(hasMapInt(&map, 42) == TRUE);
    assert(getMapInt(&map, 42) == 999);

    freeMap(&map);
    print_test_ok("test_reinsert_after_delete");
}

static void test_update_in_long_chain(void) {
    UnorderedMapInt map = createMap(1);

    for (int i = 0; i < 100; i++) {
        insertEntryInMapInt(&map, i, i);
    }

    insertEntryInMapInt(&map, 50, 9999);
    insertEntryInMapInt(&map, 0, 7777);
    insertEntryInMapInt(&map, 99, 8888);

    assert(getMapInt(&map, 50) == 9999);
    assert(getMapInt(&map, 0) == 7777);
    assert(getMapInt(&map, 99) == 8888);

    for (int i = 0; i < 100; i++) {
        if (i == 50) {
            assert(getMapInt(&map, i) == 9999);
        } else if (i == 0) {
            assert(getMapInt(&map, i) == 7777);
        } else if (i == 99) {
            assert(getMapInt(&map, i) == 8888);
        } else {
            assert(getMapInt(&map, i) == i);
        }
    }

    freeMap(&map);
    print_test_ok("test_update_in_long_chain");
}

static void test_zero_value(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 123, 0);

    assert(hasMapInt(&map, 123) == TRUE);
    assert(getMapInt(&map, 123) == 0);

    freeMap(&map);
    print_test_ok("test_zero_value");
}

/*
 * Só rode este teste se sua hashFnMapInt tratar chave negativa corretamente.
 * Exemplo correto:
 *
 * int hashFnMapInt(UnorderedMapInt *map, int key) {
 *     int h = key % map->size;
 *     return h < 0 ? h + map->size : h;
 * }
 */
static void test_negative_keys(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, -1, 111);
    insertEntryInMapInt(&map, -9, 999);
    insertEntryInMapInt(&map, -17, 1717);

    assert(hasMapInt(&map, -1) == TRUE);
    assert(hasMapInt(&map, -9) == TRUE);
    assert(hasMapInt(&map, -17) == TRUE);

    assert(getMapInt(&map, -1) == 111);
    assert(getMapInt(&map, -9) == 999);
    assert(getMapInt(&map, -17) == 1717);

    deleteEntryInMapInt(&map, -9);
    assert(hasMapInt(&map, -9) == FALSE);
    assert(getMapInt(&map, -9) == 0);

    freeMap(&map);
    print_test_ok("test_negative_keys");
}

static void test_delete_same_key_twice(void) {
    UnorderedMapInt map = createMap(8);

    insertEntryInMapInt(&map, 7, 70);
    deleteEntryInMapInt(&map, 7);
    deleteEntryInMapInt(&map, 7);

    assert(hasMapInt(&map, 7) == FALSE);
    assert(getMapInt(&map, 7) == 0);

    freeMap(&map);
    print_test_ok("test_delete_same_key_twice");
}

static void test_mixed_operations(void) {
    UnorderedMapInt map = createMap(16);

    for (int i = 0; i < 50; i++) {
        insertEntryInMapInt(&map, i, i * 100);
    }

    for (int i = 0; i < 50; i += 2) {
        deleteEntryInMapInt(&map, i);
    }

    for (int i = 1; i < 50; i += 2) {
        insertEntryInMapInt(&map, i, i * 1000);
    }

    for (int i = 0; i < 50; i++) {
        if (i % 2 == 0) {
            assert(hasMapInt(&map, i) == FALSE);
            assert(getMapInt(&map, i) == 0);
        } else {
            assert(hasMapInt(&map, i) == TRUE);
            assert(getMapInt(&map, i) == i * 1000);
        }
    }

    freeMap(&map);
    print_test_ok("test_mixed_operations");
}

static void test_resize_preserves_all_elements(void) {
    UnorderedMapInt map = createMap(2);
    int old_size = map.size;

    for (int i = 0; i < 100; i++) {
        insertEntryInMapInt(&map, i, i * 10);
    }

    assert(map.size > old_size);

    for (int i = 0; i < 100; i++) {
        assert(hasMapInt(&map, i) == TRUE);
        assert(getMapInt(&map, i) == i * 10);
    }

    freeMap(&map);
    print_test_ok("test_resize_preserves_all_elements");
}

static void test_resize_with_collisions_preserves_chain(void) {
    UnorderedMapInt map = createMap(1);
    int old_size = map.size;

    for (int i = 0; i < 50; i++) {
        insertEntryInMapInt(&map, i, i + 500);
    }

    assert(map.size > old_size);

    for (int i = 0; i < 50; i++) {
        assert(hasMapInt(&map, i) == TRUE);
        assert(getMapInt(&map, i) == i + 500);
    }

    freeMap(&map);
    print_test_ok("test_resize_with_collisions_preserves_chain");
}

static void test_resize_then_update_existing_keys(void) {
    UnorderedMapInt map = createMap(2);

    for (int i = 0; i < 40; i++) {
        insertEntryInMapInt(&map, i, i);
    }

    insertEntryInMapInt(&map, 10, 999);
    insertEntryInMapInt(&map, 25, 888);

    assert(getMapInt(&map, 10) == 999);
    assert(getMapInt(&map, 25) == 888);

    for (int i = 0; i < 40; i++) {
        if (i == 10) {
            assert(getMapInt(&map, i) == 999);
        } else if (i == 25) {
            assert(getMapInt(&map, i) == 888);
        } else {
            assert(getMapInt(&map, i) == i);
        }
    }

    freeMap(&map);
    print_test_ok("test_resize_then_update_existing_keys");
}

static void test_resize_then_delete_keys(void) {
    UnorderedMapInt map = createMap(2);

    for (int i = 0; i < 60; i++) {
        insertEntryInMapInt(&map, i, i * 3);
    }

    for (int i = 0; i < 60; i += 3) {
        deleteEntryInMapInt(&map, i);
    }

    for (int i = 0; i < 60; i++) {
        if (i % 3 == 0) {
            assert(hasMapInt(&map, i) == FALSE);
            assert(getMapInt(&map, i) == 0);
        } else {
            assert(hasMapInt(&map, i) == TRUE);
            assert(getMapInt(&map, i) == i * 3);
        }
    }

    freeMap(&map);
    print_test_ok("test_resize_then_delete_keys");
}

/* ========= Main ========= */

int main(void) {
    test_insert_and_has();
    test_update_existing_key();
    test_delete_existing_key();
    test_delete_nonexistent_key();
    test_collision_handling();
    test_delete_middle_of_collision_chain();
    test_get_nonexistent_key();
    printf("All basic tests passed.\n\n");

    test_many_insertions();
    test_extreme_collisions();

    test_delete_beginning_of_chain();
    test_delete_middle_of_chain();
    test_delete_end_of_chain();

    test_reinsert_after_delete();
    test_update_in_long_chain();
    test_zero_value();

    /* Ative só se hashFnMapInt tratar chave negativa corretamente */
    test_negative_keys();

    test_delete_same_key_twice();
    test_mixed_operations();

    test_resize_preserves_all_elements();
    test_resize_with_collisions_preserves_chain();
    test_resize_then_update_existing_keys();
    test_resize_then_delete_keys();

    printf("\nAll advanced tests passed.\n");
    return 0;
}