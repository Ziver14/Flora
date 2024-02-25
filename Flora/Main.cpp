#include<iostream>
#include<string>
#include<vector>


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

	virtual std::vector <Harvest*> produceHarvest() = 0;



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

	virtual std::vector <Harvest*> produceHarvest() override {
		std::vector<Harvest*>harvests;
		for (int i = 0; i < GetCapacity(); i++) {
			harvests.push_back(new Harvest("Apple","Green", 3));
		}
		return harvests;
	}
};

class Strawberry :public Plants {
public:
	Strawberry(std::string name_, std::string size_, std::string color_, int capacity_) :
		Plants(name_, size_, color_, capacity_) {}

	virtual std::vector <Harvest*> produceHarvest() override {
		std::vector<Harvest*>harvests;
		for (int i = 0; i < GetCapacity(); i++) {
			harvests.push_back(new Harvest("Strawberry", "Red", 0.2));
		}
		return harvests;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	std::vector<Harvest*>garden;

	AppleTree appleTree("Apple","Large", "Green", 1);
	std::vector<Harvest*>appleHarvest = appleTree.produceHarvest();
	garden.insert(garden.end(), appleHarvest.begin(), appleHarvest.end());



	Strawberry strawberry("Strawberry", "Small", "Red", 3);
	std::vector<Harvest*>strawberryHarvest = strawberry.produceHarvest();
	garden.insert(garden.end(), strawberryHarvest.begin(), strawberryHarvest.end());


	for (Harvest* harvests : garden) {
		std::cout << harvests->GetName() << std::endl;
		std::cout << harvests->GetColor() << std::endl;
		std::cout << harvests->GetWeight() << std::endl;

	}

	return 0;
}