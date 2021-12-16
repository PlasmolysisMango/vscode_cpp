#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    ScreenIndex addScreen(const Screen &);
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens; //{Screen(24, 80, ' ')}
};

class Screen {
    // friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const{
        do_display(os);
        return *this;
    }
    pos size() const {
        return height * width;
    }
    

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const{
        os << contents;
    }
};

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const 
{
    ++access_ctr;
}



inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

class Y;

class X {
    Y *ptr;
};

class Y {
    X obj;
};

int main() {
    Screen myscreen = Screen(6, 3, 'c');
    myscreen.move(1, 2).set('#').display(std::cout).move(2,1);
    const Screen blank(5, 3);
    blank.display(std::cout);
}