#include "Controller.h"
#include "fstream"
#include "sstream"
void Controller::readUsersFromFile()
{
	
    ifstream fin(this->userFile);
    string line;
    while (getline(fin, line)) {
        string token;
        vector<string> data;
        stringstream ss(line);
        while (getline(ss, token, '|'))
            data.push_back(token);
        User u(data[0], stoi(data[1]), data[2]);
        users.push_back(u);
    }
    fin.close();
}

void Controller::readItemsFromFile()
{
    ifstream fin(this->itemFile);
    string line;
    while (getline(fin, line)) {
        string token;
        vector<string> data;
        stringstream ss(line);
        while (getline(ss, token, '|'))
            data.push_back(token);

        vector<Offer> v;

        vector<string> damn;
        string dataListOffer = data[3];
        string tokenListOffer;
        stringstream ssListOffer(dataListOffer);

        while (getline(ssListOffer, tokenListOffer, ';'))
            damn.push_back(tokenListOffer);

        for (int i = 0; i < damn.size(); i++) {
            string dataOffer = damn[i];
            string tokenOffer;
            stringstream ssOffer(dataOffer);
            vector<string> yolo;
            Offer of;
            while (getline(ssOffer, tokenOffer, ',')) {
                yolo.push_back(tokenOffer);
            }
            of.userId = stoi(yolo[0]);
            of.date = yolo[1];
            of.sum = stoi(yolo[2]);
            v.push_back(of);
        }
        Item r(data[0], data[1], stoi(data[2]), v);
        items.push_back(r);
    }
    fin.close();
}

void Controller::writeItemsToFile()
{
    ofstream fout(this->itemFile);
    for (auto& it : this->items)
        fout << it.toStringFile() << "\n";
}

void Controller::addItem(string name, string category, int currPrice)
{
    vector<Offer> v = vector<Offer>();
    Offer o{};
    v.push_back(o);
    Item r(name, category, currPrice, v);
    items.push_back(r);
}

vector<User>& Controller::getAllUsers()
{
	return this->users;
}

vector<Item>& Controller::getAllItems()
{
    /*
    std::sort(acceptedIdeas.begin(), acceptedIdeas.end(), [&](const Idea& idea1, const Idea& idea2) {
        return idea1.getDuration() < idea2.getDuration();
        });
    */
    /*sort(items.begin(), items.end(), [&](Item& i1, Item& i2) {
        return i1.getPrice() < i1.getPrice();
        });*/
    for (int i = 0; i < items.size() - 1; i++)
        for (int j = i + 1; j < items.size(); j++) {
            if (items[i].getPrice() > items[j].getPrice())
                swap(items[i], items[j]);
        }
	return this->items;
}

vector<Item> Controller::getAllItemsFromGivenCategory(string category)
{
	vector<Item> x;
	for (auto& it : items) {
		if (it.getCategory() == category)
			x.push_back(it);
	}
	return x;
}

vector<string> Controller::getCategories()
{
    vector<string> v;
    for (int i = 0; i < items.size(); i++) {
        auto z = find(v.begin(), v.end(), items[i].getCategory());
        if (z == v.end())
            v.push_back(items[i].getCategory());
    }
    return v;
}
