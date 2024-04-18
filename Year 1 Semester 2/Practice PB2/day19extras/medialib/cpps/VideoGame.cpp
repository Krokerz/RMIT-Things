#include "../headers/VideoGame.h"

VideoGame::VideoGame() {}

VideoGame::VideoGame(std::string title, std::string year, std::string publisher, std::string developer) : Media(title, year), publisher(publisher), developer(developer) {}

std::vector<std::string> VideoGame::info() {
    std::vector<std::string> out = Media::info();

    out.push_back(publisher);
    out.push_back(developer);

    return out;
}

void VideoGame::print() {
    Media::print();
    std::cout << "\n\tPublisher: " << publisher << "\n\tDeveloper: " << developer;
}

void VideoGame::print(std::ostream &out) {
    Media::print(out);
    out << "\n\tPublisher: " << publisher << "\n\tDeveloper: " << developer;
}