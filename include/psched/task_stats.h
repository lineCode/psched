
#pragma once
#include <chrono>

namespace psched {

struct TaskStats {
  size_t task_id;
  size_t task_priority;

  using TimePoint = std::chrono::steady_clock::time_point;
  TimePoint arrival_time;    // time point when the task is marked as 'ready' (queued)
  TimePoint start_time;      // time point when the task is about to execute (dequeued)
  TimePoint end_time;        // time point when the task completes execution

  template <typename T>
  long long response_time() const {
    return std::chrono::duration_cast<T>(end_time - arrival_time).count();
  }

  template <typename T>
  long long computation_time() const {
    return std::chrono::duration_cast<T>(end_time - start_time).count();
  }
};

}