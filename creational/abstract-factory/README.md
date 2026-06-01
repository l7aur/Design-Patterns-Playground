# Abstract Factory Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

Provide an interface for creating families of related or dependent objects without specifying concrete classes.

## Applicability

- a system should be independent of how its products are created, composed and represented.
- there exist multiple interchangeable families/categories of products and only one needs to be active at a time.
- a familiy of related products is designed to work together and you want to enforce this.
- you want to provide a class library of products and expose just interfaces, not implementations.

## Consequences

- concrete class isolation - factories encapsulate the responsability and the process of creating concrete prodcuts; clients manipulate objects over abstract interfaces.
- facilitates changing the family/category of products; single point of modification: the factory appears only once at instantiation time.
- if products are designed to work together, abstract factory enforces this.
- adding new products is **hard**: the factory interface and all existing concrete factories must be modified.

## Implementation Issues

- generally, abstract factories are singletons.
- generally, the abstract factory defines one factory method per product, concrete factories override those methods. It implies that for each family of products a reasonable amount of code duplication exists in the concrete factory definition. This can be mitigated by using the prototype design pattern: the factory is initialized with a prototype of each product, hence no need for multiple concrete factories.
- usually, there is products are one-to-one mapped to abstract factory's methods, so adding a new product means adding a new method in the abstract factory interface. Another approach is to define a single method that takes as input parameter an `enum` value. This is suitable if all product classes have a common ancestor in the inheritance hierarchy (statically typed languages, in dynamically typed languages it is easier to implement). However, all products are returned with the same abstract product interface. Consequently, clients are forced to downcasting.