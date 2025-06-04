#include<stdlib.h>
#include<stdio.h>


// strTable's indexes are "mapped" to vTable's indexes
//      If you ask for the value "name", you will lookup the index of "name" in strTable
//      Then using that index you get a jsonValue in the vTable.

// "Data": {
//      "name": "Philip",
//      "age": 20,
//      "likes": {
//          "newtorking",
//          "programing",
//      }
//

// "vTable": {
//      (jsonValue*), // { type = char*, value = char* -> P.... (Philip) }
//      (jsonValue*), // { type = int, value = int -> 20 }
//      (jsonValue*)  // { type = jsonValue, value = jsonValue* -> {
//                                                                      type = char*, value = char* -> Newtorking, 
//                                                                      type = char*, value = char* -> Programing
//                                                                  } 
//                      }

// "strTable" (BASE): {
//      (char*)name,
//      (char*)age,
//      (char*)likes
//


enum JsonTypes { JsonValueType, IntType, StrType };

typedef struct {
    int type;
    void *value;
    
} JsonValue;

typedef struct {
    int len;

    char** strTable;
    JsonValue** vTable;

} Map;


Map* createMap() {
    // Allocate space for integer and pointers
    Map *object = (Map*)malloc(sizeof(Map));
    object->len = 0;

    // Allocate space for pointers in tables
    object->strTable = (char**)malloc(sizeof(char*));
    object->vTable = (JsonValue**)malloc(sizeof(JsonValue*));

    return object;
}

void addToObject(Map* object, char* key, int valueType, void* value) {

    //
    // Allocate for the KEY and place it in strTable
    //
    int keyLen = 0;
    while (key[keyLen] != '\0') {
        keyLen += 1;
    }
    object->strTable[object->len] = (char*)malloc(sizeof(char)*keyLen);
    object->strTable[object->len] = key;

    //
    // Allocate for JsonValue in vTavle pointer
    // 
    object->vTable[object->len] = (JsonValue*)malloc(sizeof(JsonValue));

    // Check for valueTypes and allocate apropriatly
    if (valueType = StrType) {
        object->vTable[object->len]->type = StrType;
        object->vTable[object->len]->value = (char*)value;

        (char*)object->vTable[object->len]->value;
    }

    if (valueType = IntType) {
        object->vTable[object->len]->type = IntType;
        object->vTable[object->len]->value = value;

        (int*)object->vTable[object->len]->value;
    }

    if (valueType = StrType) {
        object->vTable[object->len]->type = JsonValueType;
        object->vTable[object->len]->value = (JsonValue*)value;

        (char*)object->vTable[object->len]->value;
    }

    // Allocate pointers and increment ah
    object->len += 1; // Represents how many there are. 2 = 2 JsonValue's

    // Pray realloc does not fail
    JsonValue** jvTmp = realloc(object->vTable, sizeof(JsonValue*) * object->len+1);
    object->vTable = jvTmp;

    char** stTmp = realloc(object->strTable, sizeof(char*) * object->len+1);
    object->strTable = stTmp;

    return;
}

// YOU CANNOT REMOVE ITEMS, not allowed :)

// Hashmap? fk tht shet ah
int getObjIndex(char** strTable, char* key) {
    // Go trough each entry in strTable
    //      compare it to key,
    //      return key_index (i) or exit(1) KYS trow in a sysfault to, mafaka cant even type
    //
    return 0;
}


int main() {
    Map* object = createMap();

    char key1[10] = "name";
    void* v = "Philip";

    int v2 = 20;
    char key2[20] = "age";

    //JsonValue value = {
    //    StrType,
    //    "Philip"
    //};

    addToObject(object, key1, StrType, v); 
    addToObject(object, key2, IntType, &v2); 

    printf("INDEX-0: %s\n", object->strTable[0]);
    printf("INDEX-1: %s\n", object->strTable[1]);

    printf("IT OwO Works: %s\n", (char*)object->vTable[0]->value); 
    printf("IT OwO Works: %d\n", *(int*)object->vTable[1]->value); 

    free(object);
    //printf("Test: %d\n", new.type);
    return 0;
}
