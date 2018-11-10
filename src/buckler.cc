#include "buckler.hpp"


namespace buckler {

Buckler::Buckler() {};

Buckler::Buckler(Target _target) {
    SetUp(_target);
}

void Buckler::SetUp(Target _target) {
    repo = RepositoryUpdator();

    target = _target;
    result = Result();

    signatures = SignatureController();
    scanners = ScannerController(target);
}

Result Buckler::Scan() {
    scanners.repository.Start();

    while(scanners.repository.is_continue) {
        Scanner scanner = scanners.repository.Next();
        
        signatures.repository.Start();
        while(signatures.repository.is_continue) {
            Signature signature = signatures.repository.Next();
            bool tmp = scanner.Scan(signature);

            if(tmp) {
                result.hits.emplace(signature.path, scanner.path);                    
            }

            result.is_hit |= tmp; 
        }
    }
    
    return result;
}
}

/*
int main() {
    unsigned char hoge[] = "hogehoge";
    Buckler::Target target = Buckler::Target((unsigned char *)hoge, sizeof(hoge));
    
    Buckler::Buckler buckler = Buckler::Buckler(target);
    buckler.repo.Update();
}
*/