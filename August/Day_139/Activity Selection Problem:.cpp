def activity_selection(activities):
    activities.sort(key=lambda x: x[1])
    n = len(activities)
    selected_activities = [activities[0]]
    last_end_time = activities[0][1]
    
    for i in range(1, n):
        if activities[i][0] >= last_end_time:
            selected_activities.append(activities[i])
            last_end_time = activities[i][1]
    
    return selected_activities

# Example usage:
activities = [(1, 3), (2, 4), (3, 5), (0, 6), (5, 7), (8, 9), (5, 9)]
print(activity_selection(activities))  # Output: [(1, 3), (3, 5), (5, 7), (8, 9)]
