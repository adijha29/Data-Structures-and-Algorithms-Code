#include <iostream>
#include <string>

#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    Song(const string& title, const string& artist) : title(title), artist(artist), prev(nullptr), next(nullptr) {}
    string title;
    string artist;
    Song* prev;
    Song* next;
};

class Playlist {
private:
    Song* head;
    Song* tail;
public:
    Playlist() : head(nullptr), tail(nullptr) {}
    void addSong(const string& title, const string& artist) {
        Song* newSong = new Song(title, artist);
        if (head == nullptr) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }
    void removeSong(const string& title) {
        Song* curr = head;
        while (curr != nullptr) {
            if (curr->title == title) {
                if (curr->prev != nullptr) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                } else {
                    tail = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
        cout << "Song not found in the playlist." << endl;
    }
    void displayPlaylist() {
        cout << "Playlist:" << endl;
        Song* curr = head;
        while (curr != nullptr) {
            cout << "Title: " << curr->title << " | Artist: " << curr->artist << endl;
            curr = curr->next;
        }
    }
};

int main() {
    Playlist playlist;
    playlist.addSong("Song 1", "Artist abc");
    playlist.addSong("Song 2", "Artist def");
    playlist.addSong("Song 3", "Artist xyz");
    playlist.displayPlaylist();
    playlist.removeSong("Song 2");
    playlist.displayPlaylist();
    return 0;
}
