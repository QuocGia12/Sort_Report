import numpy as np
import time
import sys


def main():
    with open("ThoiGianSortPython.txt", "w") as output:
        for i in range(1, 11):
            filename = f"Test{i}.txt"

            try:
                data = np.loadtxt(filename, dtype=np.float64)
                start = time.perf_counter()
                sorted_data = np.sort(data)  
                duration = (time.perf_counter() - start) * 1000 
                output.write("Thoi gian ham Sort tron Python:\n")
                output.write(f"Test {i}: {round(duration)} ms\n")
                print(-1, file=sys.stderr)

            except Exception as e:
                print(f"Lỗi khi đọc file {filename}: {e}", file=sys.stderr)


if __name__ == "__main__":
    main()