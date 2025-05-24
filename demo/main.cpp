#include <iostream>

#include <QApplication>
#include <QWidget>

int main(int argc, char**argv){
    std::cout << "Hello, from windcad!\n";

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("window");
    window.show();


    return app.exec();
}
