#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
/* DO NOT EDIT THE LINES BELOW */
#define STRING_MAX 1024

typedef struct node {
    char *name;
    int lines;
    int runtime;
    int memory_usage;
    struct node *next;
} Node;

typedef struct linked_list {
    Node* head;
} LinkedList;

void readInputString(char *, int);
void readInputNumber(int *);
void readInputChar(char *);
LinkedList * newList();
char getCommand();
void handleInsert(LinkedList *);
void handleDelete(LinkedList *);
void handleSearch(LinkedList *);
void handlePrint(LinkedList *);
void handleQuit(LinkedList *);

int main() {
    LinkedList *list = newList();
    char command = '\0';
    printf("Experimental database entry\n");
    while (command != 'Q') {
        command = getCommand();
        switch (command) {
        case 'I':
        handleInsert(list);
        break;
        case 'D':
        handleDelete(list);
        break;
        case 'S':
        handleSearch(list);
        break;
        case 'P':
        handlePrint(list);
        break;
        case 'Q':
        handleQuit(list);
        break;
    }
}
    
free(list);
return 0;
    
}
/* DO NOT EDIT THE LINES ABOVE */


void handleInsert(LinkedList *list) {
    // Prompt user for node data
    int nameLen;
    printf("\nNumber of characters in file name: ");
    scanf("%d", &nameLen);
    getchar(); // To consume the newline character after scanf

    printf("File name: ");
    char* fileName = (char*)malloc((nameLen+1)*sizeof(char));
    readInputString(fileName, (nameLen+1));

    printf("Number of lines in CSV file: ");
    int numLines;
    readInputNumber(&numLines);

    printf("Experiment runtime (ms): ");
    int runtime;
    readInputNumber(&runtime);

    printf("Experiment memory usage (B): ");
    int memory;
    readInputNumber(&memory);
    
    // Search for node with the same name
    Node* current = list->head; // To keep track of which node we are at
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) { // Compare the strings correctly
            printf("\nAn entry with that file name already exists.\n");
            free(fileName); // Free the memory since it's not needed anymore
            return;
        }
        if (strcmp(current->name, fileName) > 0) {
            break;
        }
        prev = current;
        current = current->next;
    }

    // Place data in node created using malloc
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = fileName;
    newNode->runtime = runtime;
    newNode->lines = numLines;
    newNode->memory_usage = memory;
    newNode->next = NULL;

    // Insert node in the list in correct alphabetical location
    if (prev == NULL) { // If the new node should be inserted at the beginning of the list
        newNode->next = list->head;
        list->head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
    
}

void handleDelete(LinkedList *list) {
    printf("\nEnter file name to delete: ");
    char* fileName = (char*)malloc(1025 * sizeof(char));
    readInputString(fileName, 1025);

    Node* current = list->head; // To keep track of which node we are at
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) { // If we found the node we want to delete
            printf("Deleting entry for CSV file <%s>\n", fileName);
            
            if (prev == NULL) { // If the node to delete is the first node
                list->head = current->next;
            }
            
            else {
                prev->next = current->next;
            }
            
            free(current->name); // Free the memory for the name field
            free(current); // Free the memory for the node
            free(fileName); // Free the memory for the input fileName
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("An entry for file <%s> does not exist.\n", fileName);
    free(fileName); // Free the memory for the input fileName
}


void handleSearch(LinkedList *list) {
    printf("\nEnter file name to find: ");
    char* fileName = (char*)malloc(1025 * sizeof(char));
    readInputString(fileName, 1024);

    Node* current = list->head; // To keep track of which node we are at

    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) { // We found the file we are looking for
            printf("File <%s>\n", fileName);
            printf("Lines: %d\n", current->lines);
            printf("Runtime (ms): %d\n", current->runtime);
            printf("Memory usage (B): %d\n", current->memory_usage);
            printf("Throughput: %.2lf\n", (double)(current->lines) / ((double)(current->runtime) / 1000.0));
            free(fileName); // Free the memory for the input fileName
            return;
        }

        if (strcmp(current->name, fileName) > 0) {
            break;
        }

        current = current->next;
    }

    printf("An entry for file <%s> does not exist.\n", fileName);
    free(fileName); // Free the memory for the input fileName
}


void handlePrint(LinkedList *list) {

    Node* current = list->head; // To keep track of which node we are at
    printf("\nData entries:\n");
    
    if(current == NULL){
        printf("There are no data entries.\n");
        return;
    }
    
    while(current!=NULL){
        printf("\nFile <%s>\n", current->name);
        printf("Lines: %d\n", current->lines);
        printf("Runtime (ms): %d\n", current->runtime);
        printf("Memory usage (B): %d\n", current->memory_usage);
        printf("Throughput: %.2lf\n", (double)(current->lines) / ((double)(current->runtime) / 1000.0));
        current = current->next;
    }


}

void handleQuit(LinkedList *list) { // Delete all entries
    Node* current = list->head; // To keep track of which node we are at

    while (current != NULL) {
        printf("Deleting entry for CSV file <%s>\n", current->name);
        Node* nextNode = current->next;
        free(current->name); // Free the memory for the name field
        free(current); // Free the memory for the node
        current = nextNode;
    }

    list->head = NULL; // Set the head of the list to NULL
}



/* DO NOT EDIT THE LINES BELOW */
void readInputString(char *str, int length) {
    int i = 0;
    char c;
    while (i < length && (c = getchar()) != '\n') {
        str[i++] = c;
    }
    
    str[i] = '\0';
}

void readInputNumber(int *number) {
    char buf[STRING_MAX];
    readInputString(buf, STRING_MAX);
    *number = (int)strtol(buf, (char **)NULL, 10);
}

void readInputChar(char *character) {
    char buf[2];
    readInputString(buf, 2);
    *character = buf[0];
}

LinkedList* newList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

char getCommand() {
    char command;
    printf("\nSupported commands are:\n");
    printf(" I - Insert\n");
    printf(" D - Delete\n");
    printf(" S - Search\n");
    printf(" P - Print\n");
    printf(" Q - Quit\n");
    printf("\nPlease select a command: ");
    readInputChar(&command);
    
    while (command != 'I' && command != 'D' && command != 'S' && command != 'P'
        && command != 'Q') {
        printf("Invalid command <%c>, please select a command: ", command);
        readInputChar(&command);
    }
    return command;
}
/* DO NOT EDIT THE LINES ABOVE */
