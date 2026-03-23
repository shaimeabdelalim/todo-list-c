#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

char tasks[MAX_TASKS][100];
int count = 0;

void addTask() {
    printf("Inserisci task: ");
    getchar();
    fgets(tasks[count], 100, stdin);
    count++;
}

void showTasks() {
    printf("\nLista Task:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s", i + 1, tasks[i]);
    }
}

void deleteTask() {
    int num;
    printf("Numero task da eliminare: ");
    scanf("%d", &num);

    if (num > 0 && num <= count) {
        for (int i = num - 1; i < count - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        count--;
    } else {
        printf("Numero non valido!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Aggiungi Task\n");
        printf("2. Mostra Task\n");
        printf("3. Elimina Task\n");
        printf("4. Esci\n");
        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: deleteTask(); break;
        }

    } while (choice != 4);

    return 0;
}