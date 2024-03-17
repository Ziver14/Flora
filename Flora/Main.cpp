#include<iostream>
#include<string>
#include<vector>
#include<memory>


class Harvest {
public:
	Harvest(std::string name_,std::string color_,double weight_):
		name_(name_),color_(color_), weight_(weight_) {}
	
	std::string GetName() const {
		return name_;
	}

	std::string GetColor()const {
		return color_;
	}

	double GetWeight()const {
		return weight_;
	}
private:
	std::string name_;
	std::string color_;
	double weight_;
};


class Plants {
public:
	Plants(std::string name_, std::string size_, std::string color_, int capacity_) :
		name_(name_), size_(size_), color_(color_), capacity_(capacity_){}

	std::string GetSize() const  {
		return size_;
	}

	std::string GetName() const {
		return name_;
	}

	std::string GetColor()const {
		return color_;
	}

	int GetCapacity()const {
		return capacity_;
	}

	virtual std::vector <std::unique_ptr<Harvest>> produceHarvest() = 0;



private:
	std::string name_;
	std::string size_;
	std::string color_;
	int capacity_;

};

class AppleTree :public Plants {
public:
	AppleTree(std::string name_,std::string size_,std::string color_,int capacity_):
			Plants(name_,size_,color_,capacity_){}

	virtual std::vector <std::unique_ptr<Harvest>> produceHarvest() override {
		std::vector<std::unique_ptr<Harvest>>harvests;
		for (int i = 0; i < GetCapacity(); i++) {
			harvests.push_back(std::make_unique<Harvest>("Apple","Green", 3));
		}
		return harvests;
	}
};

class Strawberry :public Plants {
public:
	Strawberry(std::string name_, std::string size_, std::string color_, int capacity_) :
		Plants(name_, size_, color_, capacity_) {}

	virtual std::vector <std::unique_ptr<Harvest>> produceHarvest() override {
		std::vector<std::unique_ptr<Harvest>>harvests;
		for (int i = 0; i < GetCapacity(); i++) {
			harvests.push_back(std::make_unique<Harvest>("Strawberry", "Red", 0.2));
		}
		return harvests;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	std::vector<std::unique_ptr<Harvest>>garden;

	AppleTree appleTree("Apple","Large", "Green", 1);
	std::vector<std::unique_ptr<Harvest>>appleHarvest = appleTree.produceHarvest();
	garden.insert(garden.end(), std::make_move_iterator(appleHarvest.begin()), 
		std::make_move_iterator(appleHarvest.end()));



	Strawberry strawberry("Strawberry", "Small", "Red", 3);
	std::vector<std::unique_ptr<Harvest>>strawberryHarvest = strawberry.produceHarvest();
	garden.insert(garden.end(), std::make_move_iterator(strawberryHarvest.begin()), 
		std::make_move_iterator(strawberryHarvest.end()));


	for (const auto& harvests : garden) {
		std::cout << harvests->GetName() << std::endl;
		std::cout << harvests->GetColor() << std::endl;
		std::cout << harvests->GetWeight() << std::endl;

	}

	return 0;
}