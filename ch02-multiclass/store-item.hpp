#ifndef STOREITEM_H
#define STOREITEM_H

#include <string>

class StoreItem
{
public:
  StoreItem();
  explicit StoreItem(const std::string & name);  // avoid StoreItem item = "Item name";
  void print() const;
  ~StoreItem();
  bool equals(const StoreItem & other) const;
  void setName(std::string name);
  std::string getName() const;

private:
  std::string name;
};

#endif