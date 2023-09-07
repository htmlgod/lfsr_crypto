# lfsr_crypto

## Build
```
cmake -S . -B_build
cmake --build _build
```

## Testing
```
cmake -S . -B_build -DBUILD_TESTS=ON
cmake --build _build --target test
```
