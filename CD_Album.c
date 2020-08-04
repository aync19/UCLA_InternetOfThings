//This code is a practice for using structs. It takes in a series of inputs to add an album to your collection of songs. 
//These inputs include the album name, artist name, and a list of songs inside the album.

#include <stdio.h>
#include <string.h>
struct Song
{
        char name[100];
};
struct CD
{
        char album[100];
        char artist[100];
        struct Song track_list[20];
};

int main()
{
        struct CD newCD;
        char scanAlbum[100];
        char scanArtist[100];
        char scanSong[100];
        int albumSize = 0;

        printf("Enter the album name (using underscores instead of spaces): ");
        scanf("%s", scanAlbum);
        strcpy(newCD.album, scanAlbum);
        printf("Enter the artist's name (using underscores): ");
        scanf("%s", scanArtist);
        strcpy(newCD.artist, scanArtist);
        printf("One by one, enter the track list of the album (using underscores)\n \
        After the last track enter -0:\n");

        for (int i = 0;i<20;i++)
        {
                scanf("%s", scanSong);
                if(strcmp(scanSong,"-0") == 0)
                {
                        break;
                }
                strcpy(newCD.track_list[i].name, scanSong);
                albumSize ++;
        }

        printf("Would you like to see the information you've added?\n \
        Answer y for yes, and any other key for no: ");
        char reviewScan[10];
        scanf("%s", reviewScan);

        if(strcmp(reviewScan, "y") == 0)
        {
                printf("\nArtist: %s", newCD.artist);
                printf("\nAlbum: %s\n", newCD.album);
                for(int i = 0; i < albumSize; i++)
                {
                        printf("%d. %s\n", i+1, newCD.track_list[i].name);
                }
        }

        printf("\nThe album has been added to your collection.");
}
