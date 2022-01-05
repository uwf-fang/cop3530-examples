#ifndef STOREITEM_H
#define STOREITEM_H

#include <string>

class StoreItem
{
public:
  StoreItem();
  explicit StoreItem(std::string name);  // avoid StoreItem item = "Item name";
  void print() const;
  ~StoreItem();
  bool equals(const StoreItem & other) const;
  void SetName(string name);
  std::string SetName(std::string name);

private:
  std::string name;
};

#endif