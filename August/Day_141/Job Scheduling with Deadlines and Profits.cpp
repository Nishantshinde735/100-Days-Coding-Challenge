class Job:
    def __init__(self, job_id, deadline, profit):
        self.id = job_id
        self.deadline = deadline
        self.profit = profit

def job_scheduling(jobs):
    # Sort jobs by descending profit
    jobs.sort(key=lambda x: x.profit, reverse=True)
    
    max_deadline = max(job.deadline for job in jobs)
    result = [None] * max_deadline
    total_profit = 0
    
    for job in jobs:
        # Find a slot for the job
        for slot in range(min(max_deadline, job.deadline) - 1, -1, -1):
            if result[slot] is None:
                result[slot] = job
                total_profit += job.profit
                break
    
    return total_profit, [job.id for job in result if job is not None]

# Example usage:
jobs = [
    Job('a', 2, 100),
    Job('b', 1, 19),
    Job('c', 2, 27),
    Job('d', 1, 25),
    Job('e', 3, 15)
]

total_profit, job_sequence = job_scheduling(jobs)
print(f"Total Profit: {total_profit}")  # Output: Total Profit: 142
print(f"Job Sequence: {job_sequence}")  # Output: Job Sequence: ['a', 'c', 'e']
