#include "Portofolio.hpp"

Portofolio::Portofolio(
    const std::string& name_,
    const int id_
) : AssetComposite{ name_ }
  , id{ id_ }
{ }

void Portofolio::print(
    std::ostream &out,
    const unsigned int indent
)
{
    out << std::string(indent, ' ') << "ID: " << id << "\n";
    AssetComposite::print(out, indent);
}
