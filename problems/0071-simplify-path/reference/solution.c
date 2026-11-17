char *simplifyPath(char *path) {
    size_t length = strlen(path);
    char *buffer = malloc(length + 1);
    memcpy(buffer, path, length + 1);
    char **parts = malloc((length + 1) * sizeof(*parts));
    int count = 0;
    for (char *part = strtok(buffer, "/"); part != NULL; part = strtok(NULL, "/")) {
        if (strcmp(part, "..") == 0) {
            if (count > 0) {
                count--;
            }
        } else if (strcmp(part, ".") != 0) {
            parts[count++] = part;
        }
    }

    char *result = malloc(length + 1);
    size_t used = 0;
    for (int i = 0; i < count; i++) {
        result[used++] = '/';
        size_t size = strlen(parts[i]);
        memcpy(result + used, parts[i], size);
        used += size;
    }
    if (used == 0) {
        result[used++] = '/';
    }
    result[used] = '\0';
    free(parts);
    free(buffer);
    return result;
}
