// Section 20
// Challenge 2
//  Lists

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <string>

class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;

   public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song& rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song);
void add_a_song(std::list<Song>& playlist);
void menu(const char option, std::list<Song>& playlist, std::list<Song>::iterator& current_song);
void display_menu();
void play_current_song(const Song& song);
void display_playlist(const std::list<Song>& playlist, const Song& current_song);

void add_a_song(std::list<Song>& playlist, std::list<Song>::iterator& current_song) {
    std::string song_name{};
    std::cout << "Enter the new song name: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, song_name);
    std::string artist_name{};
    std::cout << "Enter the new song's artist name: ";
    std::getline(std::cin, artist_name);
    int rating{};
    do {
        std::cout << "Enter the new song's rating: (1-5)";
        std::cin >> rating;
    } while ((rating > 5) or (rating < 1));
    Song new_song{song_name, artist_name, rating};
    playlist.insert(current_song, new_song);
    --current_song;
}

void menu(const char option, std::list<Song>& playlist, std::list<Song>::iterator& current_song) {
    switch (option) {
        case 'F':
            current_song = playlist.begin();
            break;
        case 'N':
            ++current_song;
            if (current_song == playlist.end())
                current_song = playlist.begin();
            break;
        case 'P':
            if (current_song == playlist.begin())
                current_song = --playlist.end();
            else {
                --current_song;
            }
            break;
        case 'A':
            add_a_song(playlist, current_song);
            break;
        case 'L':
            display_playlist(playlist, *current_song);
            break;
        case 'Q':
            std::cout << "Quitting..." << std::endl;
            break;
        default:
            std::cout << "Invalid option\n";
    }
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& song) {
    // This function should display
    // Playing: followed by the song that is playing
    std::cout << "-----------------------------------------------\n";
    std::cout << "Playing: \n"
              << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {
    // This function should display the current playlist
    // and then the current song playing.

    for (auto song : playlist) {
        std::cout << song << std::endl;
    }
    play_current_song(current_song);
}

int main() {
    std::list<Song> playlist{
        {"Grapes", "Busters", 1},
        {"Gogobebe", "Mamamoo", 5},
        {"Kill this Love", "Blackpink", 4},
        {"Kingdom Come", "Red Velvet", 5},
        {"Black Dice", "Death Grips", 3},
        {"Burnt Norton", "Lana del Rey", 2}};
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char option{};
    do {
		display_menu();
        std::cin >> option;
        option = toupper(option);
        menu(option, playlist, current_song);
        if ((option != 'Q') and (option != 'L'))
            play_current_song(*current_song);
    } while (option != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}