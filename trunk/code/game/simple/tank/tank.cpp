#include <iostream>
#include <cmath>

typedef int point_t;

class Area
{
public:
  //Area();
  //Area(size_t,size_t);
  //~Area();

  size_t getX (void)
  {
    return x;
  };
  size_t getY (void)
  {
    return y;
  };
  void setX (size_t n)
  {
    x = n;
  };
  void setY (size_t n)
  {
    y = n;
  };

  size_t getWidth (void)
  {
    return width;
  };
  size_t getHeight (void)
  {
    return height;
  };
  void setWidth (size_t n)
  {
    width = n;
  };
  void setHeight (size_t n)
  {
    height = n;
  };

  void setPos (size_t nx, size_t ny)
  {
    x = nx;
    y = ny;
  };
  size_t getIntersect (Area *);
private:
  size_t width;
  size_t height;
  size_t x;
  size_t y;
};

size_t Area::getIntersect (Area * area)
{
  size_t
    hDiff = this->getY () + this->getHeight () - area->getY ();
  size_t
    wDiff = this->getX () + this->getWidth () - area->getX ();
  return (hDiff * wDiff);
}

class
  Tank:
  public
  Area
{
public:
  //Tank(size_t,size_t);
  //~Tank();
  void
  setPoints (point_t p);
  point_t
  getPoints (void);
private:
  size_t
    width;
  size_t
    height;
  point_t
    points;
};

class
  Bomb:
  public
  Area
{
public:

private:
  size_t
    width;
  size_t
    height;
};

class
  Team
{
public:
  //Team();
  //~Team();
private:
  Tank *
    tanks;
  int
    points;
};

class
  Game
{
public:
private:
};

int
main (void)
{
  Area
    a1,
    a2;
  a1.setWidth (5);
  a1.setHeight (4);
  a1.setPos (3, 2);

  a2.setWidth (20);
  a2.setHeight (10);
  a2.setPos (5, 4);

  std::cout << a2.getIntersect (&a1) << std::endl;
  return 0;
}
