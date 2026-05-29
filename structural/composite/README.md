# Composite Design Pattern Notes

## Diagram

![Diagram](figs/diagram.svg)

## Example Diagram

![My Diagram](figs/example.svg)

## Intent

- allow clients treat individual objects and composites **uniformly**.

## Applicability

- part-whole hierarchies.
- clients can ignore differences between primitives and composites.

## Consequences

- any place a client expects a primitive can be replaced by a composite.
- **facilitates** adding new kinds of components.
- **uniform** access to composite or primitive types.
- composite and primitive **type erasure** means you cannot limit a composite to certain components -> runtime checks.

## Implementation Issues

- parent references help in traversing the composites.
- sharing components helps in reducing the space requirements; instead of storing multiple parent references enhance with flyweight design pattern.
- the base abstract class should provide as much implementation as possible.
- child management operations can be declared in the base abstract class (better transparency) or in the composite (better security + each class defines only meaningful operations to its subclasses). First approach is generally better. For the second one define `Composite* Component::getGomposite()` at base class level and call it before operating on children (it implies `nullptr` check boilerplate).
- the list of children should be placed in the composite class, not at the base abstract class level to minimize storage requirements.
- child ordering can be supported depending on the implementation of the storage container.
- **caching** helps when traversing is a common operation, place it in the composite class.
- composite class should manage the lifetime of its children.