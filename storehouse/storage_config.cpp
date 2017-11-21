/* Copyright 2016 Carnegie Mellon University, NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "storehouse/storage_config.h"
// #include "storehouse/gcs/gcs_storage.h"
#include "storehouse/posix/posix_storage.h"
#include "storehouse/s3/s3_storage.h"

namespace storehouse {

// StorageConfig *StorageConfig::make_gcs_config(
//   const std::string &certificates_path,
//   const std::string &key,
//   const std::string &bucket)
// {
//   GCSConfig *config = new GCSConfig;
//   config->certificates_path = certificates_path;
//   config->key = key;
//   config->bucket = bucket;
//   return config;
// }

StorageConfig* StorageConfig::make_posix_config() { return new PosixConfig; }

StorageConfig* StorageConfig::make_s3_config(const std::string& bucket,
    const std::string& region, const std::string& endpoint) {
  S3Config* config = new S3Config;
  config->bucket = bucket;
  config->endpointOverride = endpoint;
  config->endpointRegion = region;
  return config;
}

StorageConfig* StorageConfig::make_gcs_config(const std::string& bucket) {
		S3Config* config = new S3Config;
  	config->bucket = bucket;
  	config->endpointOverride = "storage.googleapis.com";
  	config->endpointRegion = "US";

  	return config;
}
}
