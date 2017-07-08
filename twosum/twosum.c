/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct MyNode *Position;
typedef Position List;
typedef struct HashTbl *HashTable;
typedef int ElementType;
#define MinTableSize (2)



int Gcd(int a, int b)
{
    int temp;
    while(b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct MyNode{
    ElementType element;
    int value;
    Position next;
};
struct HashTbl{
    int tableSize;
    List *theLists;
};

int NextPrime(int tableSize){
    int i, j, temp;
    for(i = tableSize; ; i++){
        temp = sqrt(i);
        for(j = 2;j <= temp; j++){
            if(Gcd(j, i) != 1) break;
        }
        if(j > temp)
            return i;
    }
}

HashTable InitializeTable(int tableSize){
    HashTable h;
    int i;
    if(tableSize < MinTableSize){
        printf("Tablesize is too small!\n");
        exit(1);
    }
    h = malloc(sizeof(struct HashTbl));
    h->tableSize = NextPrime(tableSize);
    h->theLists = malloc(sizeof(List) * h->tableSize);
    for(i = 0; i < h->tableSize; i++){
        h->theLists[i] = malloc(sizeof(struct MyNode));
        if(h->theLists[i] == NULL){
            printf("Out of space!\n");
            exit(1);
        }
        h->theLists[i]->next = NULL;
    }
    return h;
}

int Hash(ElementType key, int tableSize){
    return (key % tableSize + tableSize) % tableSize;
}

Position Find(ElementType key, HashTable h){
    Position p;
    List l;
    l = h->theLists[Hash(key, h->tableSize)];
    p = l->next;
    while(p != NULL && p->element != key){
        p = p->next;
    }
    return p;
}

void Insert(ElementType key, int value, HashTable h){
    Position p, newCell;
    List l;
    p = Find(key, h);
    if(p == NULL){
        newCell = malloc(sizeof(struct MyNode));
        if(newCell == NULL){
            printf("Out of space!\n");
            exit(1);
        }
        l = h->theLists[Hash(key, h->tableSize)];
        newCell->next = l->next;
        newCell->element = key;
        newCell->value = value;
        l->next = newCell;
    }
    else{
        p->value = value;
    }
}



int* twoSum(int* nums, int numsSize, int target) {
    //解法一: 
    // int i, j, sum, *result = malloc(sizeof(int) * 2);
    // for(i = 0; i < numsSize; i++){
    //     for(j = i + 1; j < numsSize; j++){
    //         if(nums[i] + nums[j] ==  target){
    //             result[0] = i;
    //             result[1] = j;
    //             return result;
    //         }
    //     }
    // }
    // return result;
    //解法二:
    int i;
    int *result = malloc(sizeof(int) * 2);
    HashTable h = InitializeTable(numsSize);
    for(i = 0; i < numsSize; i++)
        Insert(nums[i], i, h);
    for(i = 0; i < numsSize; i++){
        Position p = Find(target - nums[i], h);
        if(p && p->value != i){
            result[0] = i;
            result[1] = p->value;
            break;
        }
    }
    return result;
    
}
