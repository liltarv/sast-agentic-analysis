#!/bin/bash
set -e

apt-get update && apt-get install -y \
    libcurl4-openssl-dev libssl-dev libsqlite3-dev \
    default-libmysqlclient-dev build-essential clang

BENCHMARK_DIR="/infer-sast_testing/benchmarks/castle"
RESULTS_DIR="/infer-sast_testing/results/infer/castle"
mkdir -p "$RESULTS_DIR"

cd "$BENCHMARK_DIR"

echo "Starting analysis with Infer v1.2.0"

for file in *.c; do
  filename=$(basename "$file" .c)
  current_out_dir="$RESULTS_DIR/infer-out_$filename"
  
  echo "Analyzing $file..."

  infer run \
    --pulse \
    --quandary \
    --bufferoverrun \
    --racerd \
    --starvation \
    --liveness \
    -o "$current_out_dir" \
    -- clang -c "$file" -I.
done

echo "Analysis complete. All files processed successfully."