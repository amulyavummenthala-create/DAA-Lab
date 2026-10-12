
#include <stdio.h>

struct Node {
    char ch;
    int freq;
    int left, right, parent;
};

int main() {
    struct Node tree[100];
    char ch[50], code[50];
    int freq[50];
    int n, i, j, total, min1, min2;
    int root, current, parent, len;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &freq[i]);

        tree[i].ch = ch[i];
        tree[i].freq = freq[i];
        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].parent = -1;
    }

    total = n;

    while (total < 2 * n - 1) {
        min1 = -1;
        min2 = -1;

        for (i = 0; i < total; i++) {
            if (tree[i].parent == -1) {
                if (min1 == -1 ||
                    tree[i].freq < tree[min1].freq) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 ||
                           tree[i].freq < tree[min2].freq) {
                    min2 = i;
                }
            }
        }

        tree[total].freq =
            tree[min1].freq + tree[min2].freq;
        tree[total].ch = '\0';
        tree[total].left = min1;
        tree[total].right = min2;
        tree[total].parent = -1;

        tree[min1].parent = total;
        tree[min2].parent = total;

        total++;
    }

    root = total - 1;

    printf("\nCharacter\tFrequency\tHuffman Code\n");

    for (i = 0; i < n; i++) {
        current = i;
        len = 0;

        while (tree[current].parent != -1) {
            parent = tree[current].parent;

            if (tree[parent].left == current)
                code[len++] = '0';
            else
                code[len++] = '1';

            current = parent;
        }

        printf("%c\t\t%d\t\t", ch[i], freq[i]);

        for (j = len - 1; j >= 0; j--)
            printf("%c", code[j]);

        printf("\n");
    }

    return 0;
}
