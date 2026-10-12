
#include <stdio.h>

struct Node {
    char ch;
    int freq;
    int left, right, parent;
};

int main() {
    struct Node tree[20];
    char letters[] = {'a', 'c', 'd', 'e', 'o',
                      'm', 's', 't', 'u'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};

    int n = 9, total = 9;
    int i, j, min1, min2, current, parent, len;
    int totalBits = 0;
    char code[20];

    for (i = 0; i < n; i++) {
        tree[i].ch = letters[i];
        tree[i].freq = freq[i];
        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].parent = -1;
    }

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

    printf("Character\tFrequency\tHuffman Code\n");

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

        printf("%c\t\t%d\t\t", letters[i], freq[i]);

        for (j = len - 1; j >= 0; j--)
            printf("%c", code[j]);

        printf("\n");

        totalBits += freq[i] * len;
    }

    printf("\nTotal frequency units = 100\n");
    printf("Total bits = %d x 100 = %d bits\n",
           totalBits, totalBits * 100);
    printf("Memory required = %d bytes\n",
           totalBits * 100 / 8);

    return 0;
}
