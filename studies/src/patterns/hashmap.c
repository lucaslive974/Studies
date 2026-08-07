#include "hashmap.h"
#include <stdint.h>
#include <stdlib.h>

EntryInt *createEntryInt(int key, int value) {
    EntryInt *entry = malloc(sizeof(EntryInt));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;

    return entry;
}

UnorderedMapInt llcreateMap(int size) {
    UnorderedMapInt map;
    map.size = size;
    map.used_buckets = 0;
    map.bucket = malloc(sizeof(void *) * size);

    for (int i = 0; i < size; i++) {
        EntryInt *entrie = createEntryInt(0, 0);
        map.bucket[i] = entrie;
    }

    return map;
}

int hashFnMapInt(UnorderedMapInt *map, int key) { return abs(key) % map->size; }

void insertEntryInMapInt(UnorderedMapInt *map, int key, int value) {
    double load_factor = (double)map->used_buckets / map->size;
    if (load_factor > 0.80)
        resizeMapInt(map);

    int idx = hashFnMapInt(map, key);

    EntryInt *prev = map->bucket[idx];
    EntryInt *tail = prev->next;

    while (tail != NULL) {
        if (tail->key == key) {
            tail->value = value;
            return;
        }
        prev = tail;
        tail = tail->next;
    }

    EntryInt *newEntry = createEntryInt(key, value);
    prev->next = newEntry;

    map->used_buckets++;
}

void deleteEntryInMapInt(UnorderedMapInt *map, int key) {
    int idx = hashFnMapInt(map, key);

    EntryInt *tail = map->bucket[idx];

    while (tail->next != NULL) {
        if (tail->next->key == key) {
            EntryInt *tmp = tail->next;
            tail->next = tail->next->next;
            free(tmp);
            return;
        }
        tail = tail->next;
    }
}

bool hasMapInt(UnorderedMapInt *map, int key) {
    int idx = hashFnMapInt(map, key);

    EntryInt *tail = map->bucket[idx]->next;

    while (tail) {
        if (tail->key == key)
            return TRUE;
        tail = tail->next;
    }

    return FALSE;
}

int getMapInt(UnorderedMapInt *map, int key) {
    int idx = hashFnMapInt(map, key);

    EntryInt *curr = map->bucket[idx]->next;

    while (curr) {
        if (curr->key == key)
            return curr->value;

        curr = curr->next;
    }

    return 0;
}

void freeMap(UnorderedMapInt *map) {
    for (int i = 0; i < map->size; i++) {
        EntryInt *curr = map->bucket[i];
        while (curr != NULL) {
            EntryInt *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(map->bucket);
}

void resizeMapInt(UnorderedMapInt *map) {
    size_t new_size = map->size * 3;
    UnorderedMapInt new_map = createMap(new_size);

    for (int i = 0; i < map->size; i++) {
        EntryInt *entry = map->bucket[i]->next;

        while (entry != NULL) {
            insertEntryInMapInt(&new_map, entry->key, entry->value);
            entry = entry->next;
        }
    }

    freeMap(map);
    *map = new_map;
}