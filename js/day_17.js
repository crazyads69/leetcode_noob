var TimeLimitedCache = function () {
  this.cacheMap = new Map(); // Lưu trữ cặp key-value
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  const now = Date.now();
  const isExisting =
    this.cacheMap.has(key) && this.cacheMap.get(key).expireTime > now;

  // Thêm key vào cache với thời gian hết hạn
  this.cacheMap.set(key, { value, expireTime: now + duration });

  return isExisting;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  const now = Date.now();

  if (this.cacheMap.has(key)) {
    const { value, expireTime } = this.cacheMap.get(key);
    if (expireTime > now) {
      return value; // Trả về giá trị nếu key chưa hết hạn
    }
    this.cacheMap.delete(key); // Xóa key nếu đã hết hạn
  }

  return -1; // Trả về -1 nếu key không tồn tại hoặc đã hết hạn
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  const now = Date.now();
  let count = 0;

  // Duyệt qua cacheMap và đếm các key chưa hết hạn
  for (const [key, { expireTime }] of this.cacheMap.entries()) {
    if (expireTime > now) {
      count++;
    } else {
      this.cacheMap.delete(key); // Xóa các key đã hết hạn
    }
  }

  return count;
};

const timeLimitedCache = new TimeLimitedCache();
console.log(timeLimitedCache.set(1, 42, 1000)); // false
console.log(timeLimitedCache.get(1)); // 42
console.log(timeLimitedCache.count()); // 1
