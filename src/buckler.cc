#include "base.cc"
#include "signature.cc"
#include "scanner.cc"
#include "utils.cc"
#include "update.cc"

#pragma once


class Buckler {
public:
    Target target;
    Result result;
    RepositoryUpdator repo;

    ScannerController scanners;
    SignatureController signatures;

    Buckler(Target _target) {
        repo = RepositoryUpdator();

        target = _target;
        result = Result();

        signatures = SignatureController();
        scanners = ScannerController(target);
    }

    Result Scan() {
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
};


int main() {
    unsigned char hoge[] = "hogehoge";
    Target target = Target((unsigned char *)hoge, sizeof(hoge));
    
    Buckler buckler = Buckler(target);
    buckler.repo.Update();
}
