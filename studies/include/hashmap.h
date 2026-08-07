#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef struct EntryInt {
    int key;
    int value;
    struct EntryInt *next;
} EntryInt;

typedef struct UnorderedMapInt {
    size_t size;
    size_t used_buckets;
    EntryInt **bucket;
} UnorderedMapInt;

UnorderedMapInt llcreateMap(int size);

EntryInt *llcreateEntryInt(int key, int value);

void insertEntryInMapInt(UnorderedMapInt *map, int key, int value);

void deleteEntryInMapInt(UnorderedMapInt *map, int key);

bool hasMapInt(UnorderedMapInt *map, int key);

int getMapInt(UnorderedMapInt *map, int key);

void resizeMapInt(UnorderedMapInt *map);

void freeMap(UnorderedMapInt *map);

#define createMap(...) llcreateMap(__VA_ARGS__ > 0 ? __VA_ARGS__ : (2 << 10))