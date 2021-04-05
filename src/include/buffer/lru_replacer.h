//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.h
//
// Identification: src/include/buffer/lru_replacer.h
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <iterator>
#include <list>
#include <mutex>  // NOLINT
#include <unordered_map>
#include <vector>

#include "buffer/replacer.h"
#include "common/config.h"

namespace bustub {

/**
 * LRUReplacer implements the lru replacement policy, which approximates the
 * Least Recently Used policy.
 */
using Frame_t = struct Frame {
  frame_id_t frame_id;
  bool referenced;
};
using Frame_it = std::vector<Frame_t>::iterator;

class LRUReplacer : public Replacer {
 public:
  /**
   * Create a new LRUReplacer.
   * @param num_pages the maximum number of pages the LRUReplacer will be
   * required to store
   */
  explicit LRUReplacer(size_t num_pages);

  /**
   * Destroys the LRUReplacer.
   */
  ~LRUReplacer() override;

  bool Victim(frame_id_t *frame_id) override;

  void Pin(frame_id_t frame_id) override;

  void Unpin(frame_id_t frame_id) override;

  size_t Size() override;

  bool HasFrame(frame_id_t frame_id) override;

 private:
  // TODO(student): implement me!
  std::vector<frame_id_t> replacement_pool_;
  std::unordered_map<frame_id_t, bool> is_referenced;
  size_t pointer_ = 0;
};

}  // namespace bustub
