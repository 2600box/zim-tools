#ifndef OPENZIM_ZIMFS_H
#define OPENZIM_ZIMFS_H

#include <string>
#include <unordered_map>

#include <zim/archive.h>
#include <zim/item.h>

#define INVALID_INDEX 0xffffffff

class ZimFSNode
{
  std::string name;

public:
  zim::entry_index_type entry_index;
  std::unordered_map<std::string, ZimFSNode*> children;

  ZimFSNode();
  ZimFSNode(const std::string& name, zim::entry_index_type index);

  void addEntry(const zim::Entry& entry);
  ZimFSNode* findPath(const std::string& path);


  ~ZimFSNode();
};

class ZimFS
{
public:

  zim::Archive archive;
  ZimFSNode root;
  ZimFS(const std::string& fname, bool check_intergrity);

  void printInfo();
};


#endif //OPENZIM_ZIMFS_H