#include "../headers/AudioBook.h"

AudioBook::AudioBook() {}

AudioBook::AudioBook(std::string title, std::string year, std::string author, std::string narrator) : Media(title, year), author(author), narrator(narrator) {}

std::vector<std::string> AudioBook::info() {
    std::vector<std::string> out = Media::info();

    out.push_back(author);
    out.push_back(narrator);

    return out;
}

void AudioBook::print() {
    Media::print();
    std::cout << "\n\tNarrator: " << narrator << "\n\tAuthor: " << author;
}

void AudioBook::print(std::ostream &out) {
    Media::print(out);
    out << "\n\tNarrator: " << narrator << "\n\tAuthor: " << author;
}