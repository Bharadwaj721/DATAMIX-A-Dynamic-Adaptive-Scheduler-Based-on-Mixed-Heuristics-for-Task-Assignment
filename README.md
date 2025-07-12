# DATAMIX: A Dynamic Adaptive Task Assignment Algorithm Based on Mixed Heuristics

## Introduction

Efficient task scheduling is critical in distributed and heterogeneous computing environments such as cloud systems and data centers. Traditional heuristics like Minimum Completion Time (MCT) and Minimum Execution Time (MET) often struggle to generalize well across diverse workloads. To address this, we propose **DATAMIX**, a lightweight and adaptive task scheduling algorithm that dynamically blends both MCT and MET using a threshold-based decision mechanism.

---

## Problem Statement

Given a matrix of execution times where each row represents a task and each column represents a machine, the objective is to assign each task to exactly one machine in such a way that the **maximum completion time** (makespan) across all machines is minimized.

---

## Proposed Algorithm: DATAMIX

DATAMIX works in four main stages:

- **Input**: The algorithm reads a task-machine execution time matrix.
- **Initialization**: A vector is initialized to keep track of each machine’s total completion time.
- **Task Assignment**:
  - For each task:
    - Identify `mn1`: machine with the least load + task time (MCT).
    - Identify `mn2`: machine with the minimum execution time (MET).
    - Compute a dynamic threshold from task execution time distribution.
    - Compare assignment difference between `mn1` and `mn2`.
    - Assign the task to `mn2` if the difference is within the threshold; else to `mn1`.
- **Output**: The final makespan is the maximum value from the load vector.

---

## Experimental Results

We tested DATAMIX on 12 standard benchmark datasets from the task scheduling domain and compared it against:

- OLB (Opportunistic Load Balancing)
- MCT (Minimum Completion Time)
- MET (Minimum Execution Time)
- SA (Simulated Annealing)
- kPB (k Percent Best)

Below is the comparison of makespan values (lower is better):

| Instance      | OLB           | MCT           | MET           | SA            | kPB           | **DATAMIX**     |
|---------------|----------------|----------------|----------------|----------------|----------------|----------------|
| u_c_hihi.0     | 14,376,662.18  | 11,422,624.49  | 47,472,299.43  | 16,213,221.10  | 12,496,863.71  | **12,588,764.44** |
| u_c_hilo.0     | 221,051.82     | 185,887.40     | 1,185,092.97   | 194,549.79     | 201,153.96     | **190,692.49**     |
| u_c_lohi.0     | 477,357.02     | 378,303.62     | 1,453,098.00   | 426,271.39     | 400,291.05     | **390,061.11**     |
| u_c_lolo.0     | 7,306.60       | 6,360.05       | 39,582.30      | 8,167.05       | 6,846.27       | **6,342.29**       |
| u_i_hihi.0     | 26,102,017.62  | 4,413,582.98   | 4,508,506.79   | 4,692,192.00   | 4,508,655.93   | **3,978,575.72** |
| u_i_hilo.0     | 272,785.20     | 94,855.91      | 96,610.48      | 98,002.38      | 93,005.90      | **84,634.44**      |
| u_i_lohi.0     | 833,605.65     | 143,816.09     | 185,694.59     | 143,905.25     | 131,816.08     | **130,200.24**     |
| u_i_lolo.0     | 89,380.27      | 3,137.35       | 3,399.28       | 3,485.29       | 3,122.96       | **2,997.18**       |
| u_s_hihi.0     | 19,464,875.91  | 6,693,923.90   | 25,162,058.14  | 7,127,729.95   | 6,514,162.15   | **6,501,910.29** |
| u_s_hilo.0     | 250,362.11     | 126,587.59     | 605,363.77     | 149,050.29     | 123,543.79     | **117,815.33**     |
| u_s_lohi.0     | 603,231.47     | 186,151.29     | 674,689.54     | 194,318.37     | 187,955.96     | **176,034.11**     |
| u_s_lolo.0     | 8,938.39       | 4,436.12       | 21,042.41      | 5,836.96       | 4,405.25       | **4,268.67**       |

**Result:** DATAMIX outperforms MCT in **9 out of 12** instances.

---

## Key Contributions

- Designed an adaptive task assignment strategy that blends MCT and MET heuristics based on dynamic thresholds.
- Achieved superior performance over traditional methods on standard benchmark datasets.
- Demonstrated robustness and generalizability across diverse task and machine distributions.

---

## Tools and Technologies

- Language: C++
- Editor: Visual Studio Code
- Data: Standard Benchmark Files
- Evaluation: Makespan comparison across 12 instances

---

## Conclusion

DATAMIX is a simple yet effective scheduling algorithm that dynamically adapts its decision strategy per task. Unlike fixed-heuristic methods, it leverages both load balancing and task efficiency characteristics to deliver better overall makespan. It is ideal for heterogeneous or dynamic task environments such as cloud computing platforms, grid systems, or edge networks.

---

## License

This project is licensed under the MIT License.

---

## Acknowledgment

This work builds upon insights from traditional scheduling heuristics and contributes a new adaptive hybrid that can inspire further dynamic scheduling strategies.



