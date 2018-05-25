#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define HASH_SIZE 97


struct  hash_node {
    int key;
    int val;
    struct hash_node* next;
};

struct hash_map {
    int size;
    struct hash_node* entry;
};


void hash_init(struct hash_map* hash) {
    hash->size = HASH_SIZE;
    hash->entry = (struct hash_node*)malloc(sizeof(struct hash_node)*hash->size);
    for (int i = 0; i < hash->size; ++i)
        hash->entry[i].next = NULL;
}

int hash_get_hash_index(const struct hash_map* hash, int key) {
    return abs(key)%hash->size;
}

void hash_insert(struct hash_map* hash, int key, int val) {
    int index = hash_get_hash_index(hash, key);
    struct hash_node* p = hash->entry + index;
    struct hash_node* new_node = (struct hash_node*)malloc(sizeof(struct hash_node));
    new_node->key  = key;
    new_node->val  = val;
    new_node->next = p->next;
    p->next = new_node;
}

int  hash_find(const struct hash_map* hash, int key) {
    int index = hash_get_hash_index(hash, key);
    struct hash_node* p = hash->entry + index;
    while (p->next != NULL) {
        p = p->next;
        if (p->key == key)
            return p->val;
    }
    return -1;
}

void hash_free(struct hash_map* hash) {
    for (int i = 0; i < hash->size; ++i) 
        if (hash->entry[i].next != NULL) {
            struct hash_node* p = hash->entry[i].next;
            hash->entry[i].next = p->next;
            free(p);
        }
}

int* twoSum(int* nums, int numsSize, int target) {
    struct hash_map hash;
    hash_init(&hash);
    for (int i = 0; i < numsSize; ++i) {
        int index = hash_find(&hash, target - nums[i]);
        if (index != -1) {
            int* result = (int*)malloc(sizeof(int)*2);
            result[0] = index;
            result[1] = i;
            hash_free(&hash);
            return result;
        }
        hash_insert(&hash, nums[i], i);
    }
    hash_free(&hash);
    return NULL;
}

int main()
{
    int nums[4] = {2,7,11,15};
    int *ret = NULL;
    ret = twoSum(nums, 4, 9);
    printf("%d %d\n", ret[0], ret[1]);
    return 0;
}

