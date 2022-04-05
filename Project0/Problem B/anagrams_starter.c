#include <stdio.h>
#include <assert.h>

#define SIZE 26

int are_anagrams(char[], char[]);

int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";

    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");

    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";

    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");
    
    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";

    assert(are_anagrams(listen, silent));
    printf("passed!\n");

    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";

    assert(!are_anagrams(mole, meal));
    printf("passed!\n");

    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";

    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}

int are_anagrams(char first_word[], char second_word[]) {
    int x = 0;
    int y = 0;
    int a[SIZE] = {0};
    int b[SIZE] = {0};
    while(first_word[x] != '\0'){
        a[first_word[x] - 'a']++;
        x++;
    }
    while(second_word[y] != '\0'){
        b[second_word[y] - 'a']++;
        y++;
    }
    for( int i = 0; i < SIZE; i++ ){
        if( a[i] != b[i] ){
            return 0;
        }
    }

    return 1;
}
