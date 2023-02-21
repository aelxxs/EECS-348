#include <stdio.h>

int deptAssignments[5] = {-1, -1, -1, -1, -1};
int assignmentProgress[5] = {1, 1, 1, 1, 1};

int main() {
    FILE *file = fopen("data.txt", "r");

    int deptPref[5][5];
    int progPref[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%d", &deptPref[j][i]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%d", &progPref[j][i]);
        }
    }

    int completed = 0;

    while (!completed) {
        completed = 1;
        for (int i = 0; i < 5; i++) {
            if (deptAssignments[i] == -1) {
                completed = 0;

                for (int j = 0; j < 5; j++) {
                    if (assignmentProgress[deptPref[i][j] - 1] == 1) {
                        deptAssignments[i] = deptPref[i][j] - 1;

                        assignmentProgress[deptPref[i][j] - 1] = 0;

                        break;
                    } else {
                        int progress = deptAssignments[deptPref[i][j] - 1];
                        int curDept = 0;
                        int newDept = 0;

                        for (int k = 0; k < 5; k++) {
                            if (progPref[deptPref[i][j] - 1][k] == i + 1) {
                                newDept = k;
                            }
                            if (progPref[deptPref[i][j] - 1][k] == progress + 1) {
                                curDept = k;
                            }
                        }

                        if (newDept < curDept) {
                            deptAssignments[i] = deptPref[i][j] - 1;
                            assignmentProgress[deptPref[i][j] - 1] = 0;
                            deptAssignments[progress] = -1;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("Department #%d will get Programmer #%d\n", i + 1, deptAssignments[i] + 1);
    }

    return 0;
}
