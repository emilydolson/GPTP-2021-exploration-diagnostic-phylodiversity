#!/bin/bash

EXP_TAG=exploration_metric
EXP_DIR=/mnt/scratch/dolsonem/GPTP-2021-exploration-diagnostic-phylodiversity/data/${EXP_TAG}
BASE_DATA_DIR=/mnt/scratch/dolsonem/GPTP-2021-exploration-diagnostic-phylodiversity/data/${EXP_TAG}

REPLICATES=50
CONFIG_DIR=${EXP_DIR}/../config
JOB_DIR=${BASE_DATA_DIR}

python3 gen-sub.py --data_dir ${BASE_DATA_DIR} --config_dir ${CONFIG_DIR} --replicates ${REPLICATES} --job_dir ${JOB_DIR}
