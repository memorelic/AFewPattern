#include <memory>
#include <string>
#include <iostream>
#include <typeinfo>
#include <cmath>

class Object
{

};

class RodD : public Object
{};

class Dragger : public RodD
{};

class Sabre : public RodD
{};

class Sword : public RodD
{};

class PlateD : public Object
{};

class Gold : public PlateD
{};

class Silver : public PlateD
{};

class Brass : public PlateD
{};

class Copper : public PlateD
{};

class Wood : public PlateD
{};

class PointD : public Object
{
protected:
    int x;
    int y;
public:
    PointD(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    virtual double distanceToO() = 0;
    virtual std::string toString() = 0;

    virtual bool closerToO(std::shared_ptr<PointD> p)
    {
        return distanceToO() <= p->distanceToO();
    }
};

class CartesianPt : public PointD
{
public:
    CartesianPt(int _x, int _y) : PointD{_x, _y}
    {

    }
    // --------------------------
public:
    std::string toString() override
    {
        // return std::string{ typeid(this).name() };
        return std::string(__FUNCTION__) + "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
    double distanceToO() override
    {
        return std::sqrt(x * x + y * y);
    }
};

class ManhattanPt : public PointD
{
public:
    ManhattanPt(int _x, int _y) : PointD{ _x, _y }
    {

    }
    // ---------------------------
    std::string toString() override
    {
        return std::string(__FUNCTION__) + "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
    double distanceToO() override
    {
        return static_cast<double>(x) + static_cast<double>(y);
    }
    
};

class NumD : public Object
{
public:
    virtual std::string toString() = 0;
};

class Zero : public NumD
{
public:
    std::string toString() override
    {
        return std::string(__FUNCTION__) + "()";
    }
};

class OneMoreThan : public NumD
{
    std::shared_ptr<NumD> predecessor;
public:
    OneMoreThan(std::shared_ptr<NumD> _p)
    {
        predecessor = _p;
    }
    std::string toString() override
    {
        return std::string(__FUNCTION__) + "()";
    }
};

class ShishD : public Object
{
public:
    virtual bool onlyOnions() = 0;
    virtual bool isVegetarian() = 0;
};

class Skewer : public ShishD
{
public:
    virtual bool onlyOnions() override
    {
        return true;
    }
    virtual bool isVegetarian() override
    {
        return true;
    }
};

class Onion : public ShishD
{
    std::shared_ptr<ShishD> s;
public:
    Onion(std::shared_ptr<ShishD> _s)
    {
        s = _s;
    }
    virtual bool onlyOnions() override
    {
        return s->onlyOnions();
    }
    virtual bool isVegetarian() override
    {
        return s->isVegetarian();
    }
};

class Lamb : public ShishD
{
    std::shared_ptr<ShishD> s;
public:
    Lamb(std::shared_ptr<ShishD> _s)
    {
        s = _s;
    }
    virtual bool onlyOnions() override
    {
        return false;
    }
    virtual bool isVegetarian() override
    {
        return false;
    }
};

class Tomato : public ShishD
{
    std::shared_ptr<ShishD> s;
public:
    Tomato(std::shared_ptr<ShishD> _s)
    {
        s = _s;
    }
    virtual bool onlyOnions() override
    {
        return false;
    }
    virtual bool isVegetarian() override
    {
        return s->isVegetarian();
    }
};

class KebabD : public Object
{
public:
    virtual bool isVeggie() = 0;
    virtual std::shared_ptr<Object> whatHolder() = 0;
};

class Holder : public KebabD
{
    std::shared_ptr<Object> o;
public:
    Holder(std::shared_ptr<Object> _o)
    {
        o = _o;
    }
    virtual bool isVeggie() override
    {
        return true;
    }
    virtual std::shared_ptr<Object> whatHolder() override
    {
        return o;
    }
};

class Shallot : public KebabD
{
    std::shared_ptr<KebabD> k;
public:
    Shallot(std::shared_ptr<KebabD> _k)
    {
        k = _k;
    }
    virtual bool isVeggie() override
    {
        return k->isVeggie();
    }
    virtual std::shared_ptr<Object> whatHolder() override
    {
        return k->whatHolder();
    }
};

class Shrimp : public KebabD
{
    std::shared_ptr<KebabD> k;
public:
    Shrimp(std::shared_ptr<KebabD> _k)
    {
        k = _k;
    }
    virtual bool isVeggie() override
    {
        return false;
    }
    virtual std::shared_ptr<Object> whatHolder() override
    {
        return k->whatHolder();
    }
};

class Radish : public KebabD
{
    std::shared_ptr<KebabD> k;
public:
    Radish(std::shared_ptr<KebabD> _k)
    {
        k = _k;
    }
    virtual bool isVeggie() override
    {
        return k->isVeggie();
    }
    virtual std::shared_ptr<Object> whatHolder() override
    {
        return k->whatHolder();
    }
};

class Pepper : public KebabD
{
    std::shared_ptr<KebabD> k;
public:
    Pepper(std::shared_ptr<KebabD> _k)
    {
        k = _k;
    }
    bool isVeggie() override
    {
        return k->isVeggie();
    }
    std::shared_ptr<Object> whatHolder() override
    {
        return k->whatHolder();
    }
};

class PizzaD : public Object
{
public:
    virtual std::shared_ptr<PizzaD> removeAnchovy() = 0;
    virtual std::string toString() = 0;
};

class Crust : public PizzaD
{
public:
    virtual std::shared_ptr<PizzaD> removeAnchovy()
    {
        return std::make_shared<Crust>();
    }
    virtual std::string toString()
    {
        return "Crust()";
    }
};

class Cheese : public PizzaD
{
private:
    std::shared_ptr<PizzaD> p;
public:
    Cheese(std::shared_ptr<PizzaD> _p)
    {
        p = _p;
    }
    virtual std::shared_ptr<PizzaD> removeAnchovy()
    {
        return std::make_shared<Cheese>(p->removeAnchovy());
    }
    virtual std::string toString()
    {
        return std::string{"Cheese("} + p->toString() + ")";
    }
};

class Olive : public PizzaD
{
private:
    std::shared_ptr<PizzaD> p;
public:
    Olive(std::shared_ptr<PizzaD> _p)
    {
        p = _p;
    }
    virtual std::shared_ptr<PizzaD> removeAnchovy()
    {
        return std::make_shared<Olive>(p->removeAnchovy());
    }
    virtual std::string toString()
    {
        return std::string{ "Olive(" } + p->toString() + ")";
    }
};

class Anchovy : public PizzaD
{
private:
    std::shared_ptr<PizzaD> p;
public:
    Anchovy(std::shared_ptr<PizzaD> _p)
    {
        p = _p;
    }
    virtual std::shared_ptr<PizzaD> removeAnchovy()
    {
        return p->removeAnchovy();
    }
    virtual std::string toString()
    {
        return std::string{ "Anchovy(" } + p->toString() + ")";
    }
};


class Sausage : public PizzaD
{
private:
    std::shared_ptr<PizzaD> p;
public:
    Sausage(std::shared_ptr<PizzaD> _p)
    {
        p = _p;
    }
    virtual std::shared_ptr<PizzaD> removeAnchovy()
    {
        return std::make_shared<Sausage>(p->removeAnchovy());
    }
    virtual std::string toString()
    {
        return std::string{ "Sausage(" } + p->toString() + ")";
    }
};

int main(void)
{
    auto x = std::make_shared<ManhattanPt>(2, 4);
   

    auto y =
        std::make_shared<Anchovy>(
            std::make_shared<Olive>(
                std::make_shared<Anchovy>(
                    std::make_shared<Anchovy>(
                        std::make_shared<Cheese>(
                            std::make_shared<Crust>())))));
    std::cout << y->removeAnchovy()->toString() << std::endl;
    return 0;
}