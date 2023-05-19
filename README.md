# Perlin Noise-Based 2D Map Generation using OOP: Creating a Dynamic World with Biomes and Structures

### Perlin Noise and 2D map generation using object-oriented programming (OOP).

The project revolves around creating a world consisting of various biomes, which are essentially chunks of the world. Each chunk is represented by a class that can be categorized into two types: Structure and Biome. The Structure type further subclasses into Town, Castle, and Village, while the Biome type encompasses DarkForest, LightForest, Plain, Lake, and Mountain. Each class contains specific fields corresponding to their respective actions, which are performed through their methods.

The PerlinNoise class is responsible for generating Perlin Noise, which serves as the basis for creating the entire world. The ShowField class handles the display of menus and information on the console. The Menu class represents the main menu, offering options such as creating a map, saving the map to a file, loading a map, setting field values, getting field values, and exiting the program.

The Structure and Biome classes are abstract, providing a foundation for defining individual chunks. Structures are generated with a 10% chance, and each structure subtype has approximately a 30% chance of occurrence. Biomes, on the other hand, represent different natural environments.

The project incorporates exception handling to handle errors effectively. Instead of conventional arrays, the project utilizes vectors from the Standard Template Library (STL). Additionally, arrays of classes are implemented using unique_ptr.

The size of the fields can be dynamically set during program execution, with a preference for sizes that have an integer square root to ensure an aesthetically pleasing map and its chunks.

Furthermore, the map can be saved to a file and loaded as desired, allowing for persistence of the generated world.

The Biome class contains the following main fields (used for getters):

 - name (string)
 - age (int)

The Structure class contains the following main fields (used for getters):

 - name (string)
 - age (int)
 - owner (string)
 - population (int)

Perlin Noise, a type of procedural texture, is a key component of the project. It is widely used by artists to add realism to computer graphics. The algorithm generates pseudo-random results, ensuring that all visual details have a consistent size. Its versatility lies in the ability to scale and apply Perlin noise to mathematical expressions, facilitating the creation of diverse procedural textures. This technique is particularly useful for achieving realistic computer-generated effects such as fire, smoke, clouds, or other natural phenomena. Perlin noise also proves valuable in scenarios with limited memory, such as demo scenes or real-time graphics in games.
