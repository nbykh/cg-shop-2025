#include <catch2/catch_session.hpp>

int main(int argc, char *argv[]) {
    Catch::Session session;
    session.applyCommandLine(argc, argv);
    return session.run();
}