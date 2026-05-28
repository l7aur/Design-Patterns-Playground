#include "Account.hpp"

Account::Account(
    const std::string& name_,
    const int owner_id_
) : AssetComposite{ name_ }
  , owner_id{ owner_id_ }
{ }

void Account::print(
    std::ostream &out,
    const unsigned int indent
)
{
    out << std::string(indent, ' ') << "Owner: " << owner_id << " ";
    AssetComposite::print(out, indent);
}
