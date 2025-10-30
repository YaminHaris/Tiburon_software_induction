 from setuptools import setup, find_packages

package_name = 'interfaces'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(where='interfaces'),
    package_dir={'': 'interfaces'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email',
    description='Your description',
    license='Your license',
    entry_points={
        'console_scripts': [
            'draw_shape_service = interfaces.shape_service:main',
        ],
    },
)
     
                      
                    
                                        
                            
                                    
                  
                           
                                              
                                   
                           
                  
                            
                                                                 
          
      
 

