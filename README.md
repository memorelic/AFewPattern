# Notes

## Tips

1. When specifying a collection of data, use abstract classes for datatypes and extend classes for variants.

## Important Hints

1. A type is a name of a collection of values;
2. **abstract class** (in C++, a class with virtual funcition) introduces a new type,
   **class** introduces a variant,
   **extends** connects a variant to a datatype (in C++, use ":" ).

3. In general, if two things are instances of two different basic types, they cannot be the same.
4. An **abstract** method belong in an **abstract class** introduces an obligation, which says that all concrete classes that extend this abstract class must contain a matching method definition.