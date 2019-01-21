#include "buckler.hpp"


namespace buckler {

Buckler::Buckler() {};

Buckler::Buckler(Target target) : target(target) {
    result = Result();
}

void Buckler::Load() {
    signatures.Load();
    scanners.Load();
}

Result Buckler::Scan() {
    Result result = Result();
    scanners.list.Start();

    while(scanners.list.is_continue) {
        Scanner scanner = scanners.list.Next();

        signatures.list.Start();
        while(signatures.list.is_continue) {
            Signature signature = signatures.list.Next();
        
            Result _result = scanner.Scan(target, signature);

            if(_result.has_hit) {
                result.Include(_result);
            }
        }
    }    
    return result;
}
}
