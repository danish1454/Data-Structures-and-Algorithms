import time

start = time.time()

# Code to measure
for i in range(1000000):
    print(i)

end = time.time()

# Total time taken
print(f"Total time taken: {end - start:.6f} seconds")
