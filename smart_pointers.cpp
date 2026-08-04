#include <ios>
#include <iostream>
#include <memory>
#include <format>
class Entity {
public:
    static int count;

    Entity() {
        count++;
        std::cout << "Created entity!\n";
    }

    ~Entity() {
        std::cout << "Destroyed entity!\n";
    }

    static int get_count() {
        return count;
    }
};

int Entity::count = 0;




void pointers_experiments(){

    auto s1 = std::make_shared<Entity>();
    std::cout<<s1.use_count() << std::endl;
    auto s2 = std::make_shared<Entity>();

    std::cout<<s2.use_count() << std::endl;
    std::weak_ptr<Entity> w = s1;

    std::cout<<s2.use_count() << std::endl;
    s2.reset();
  std::cout<<s1.use_count()<<std::endl;
  s1.reset();
  std::cout<<std::boolalpha<<w.expired()<<std::endl;
}


std::string something(std::string & a, std::string& b){

  if(a.empty()){
    std::cout<<"A is empty!" << std::endl;
    return std::string("");
  }else if(b.empty()){
    std::cout <<"B is empty!" << std::endl;
    return std::string("");
  }
  return a.append(" ").append(b);
}


int main() {
  std::string a;
  std::string b;
    std::cin>>a;
  std::cin>>b;
  std::string message= something(a,b);
  std::cout <<std::format("your message! {}",message );
    // pointers_experiments();
    // const char* message = "Hello";
    // Entity e1;  
    // Entity e2;
    // std::cout << std::format("Entity count: {}", Entity::get_count()) << '\n';
    //
    // std::shared_ptr<Entity> e0;
    //
    // {
    //     std::shared_ptr<Entity> shared_ptr = std::make_shared<Entity>();
    //     e0 = shared_ptr;
    //
    //     std::cout << "Inside block\n";
    // } // shared_ptr is destroyed here, but e0 still owns the object.
    // std::unique_ptr<Entity> entity (new Entity());
    // std::unique_ptr<Entity> something = std::move(entity);
    // if(entity == nullptr){std::cout<<"its a null ptr" << std::endl;}
    //
    // std::cout << "After block\n";
    // std::cout << message << '\n';
    //
    std::cin.get();
    return 0;
}
