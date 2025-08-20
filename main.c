#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

int getErr(char err_name[], char err_desc[]) {
	printf("ERROR %s: %s\n", err_name, err_desc);
	return 1;
}

int checkArgNum(int i, char *argv[]) {
	if (argv[i] == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int checkCompString(int i, char *argv[], char string[]) {
	if (strcmp(argv[i], string) == 0) {
		return 0;
	} else {
		return 1;
	}
}

int checkErrNoArg(int argc) {
	if (argc <= 1) {
		printf("Usage: alc <command> <arg>\n");
		return 1;
	}
	return 0;
}

void createFolder(char name[]) {
	if (name != NULL) {
		_mkdir(name);
		printf("Succesfully created folder %s\n", name);
	} else {
		printf("Folder name is NULL, creating folder 'DEFAULT'\n");
		_mkdir("DEFAULT");
	}
}

void deleteFolder(char name[]) {
	char cmd[128] = {0};
	sprintf(cmd, "rmdir %s", name);
	if (name != NULL) {
		system(cmd);
		printf("Succesfully deleted '%s' folder\n", name);
	} else {
		getErr("FolderError", "failed to remove folder");
	}
}

void deleteFile(char name[]) {
	if (name != NULL) {
		remove(name);
		printf("Succesfully deleted '%s' file\n", name);
	} else {
		getErr("FileError", "failed to delete file");
	}
}

void createFile(char name[]) {
	const char* filename = name;
	FILE* file = fopen(filename, "w");

	if (file != NULL) {
		printf("Succesfully created file %s\n", filename);
	} else {
		getErr("FileError", "failed to create file");
	}

	fclose(file);
	
}

void printViaArgs(int argc, char *argv[]) {
	for (int i = 2; i < argc; i++) {
		printf("%s", argv[i]);
		if (i < argc - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

void cmdViaArgs(int argc, char *argv[]) {
	char cmd[1024] = {0};
	for (int i = 2; i < argc; i++) {
		strcat(cmd, argv[i]);
		if (i < argc - 1) strcat(cmd, " ");
	}
	system(cmd);
}

void checkCommand(int argc, char *argv[]) {
	if (checkCompString(1, argv, "create") == 0) {
		if (checkArgNum(2, argv) == 0) {
			if (checkCompString(2, argv, "folder") == 0) {
				createFolder(argv[3]);
			} else if (checkCompString(2, argv, "file") == 0) {
				createFile(argv[3]);
			}
		}
	} else if (checkCompString(1, argv, "console") == 0) {
		if (checkArgNum(2, argv) == 0) {
			printViaArgs(argc, argv);
		}
	} else if (checkCompString(1, argv, "callcmd") == 0) {
		if (checkArgNum(2, argv) == 0) {
			cmdViaArgs(argc, argv);
		}
	} else if (checkCompString(1, argv, "delete") == 0) {
		if (checkArgNum(2, argv) == 0) {
			if (checkCompString(2, argv, "folder") == 0) {
				deleteFolder(argv[3]);
			} else if (checkCompString(2, argv, "file") == 0) {
				deleteFile(argv[3]);
			}
		}
	}
	
}

int main (int argc, char *argv[]) {

	checkErrNoArg(argc);
	checkCommand(argc, argv);
	
	return 0;
}
