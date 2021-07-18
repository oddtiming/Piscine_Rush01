int *copy_array(int N) {
    int *copy;
    int i;

    i = 0;
    copy = (int *)malloc(N * N * (N + 1) * (sizeof(int)));
    while i < ((N + 1) * N * N) {
        copy[i] = STRUCT_NAME.array;
        i++;
    }
    return (copy);
}